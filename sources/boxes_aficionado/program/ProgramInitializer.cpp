//
// Created by Piotr Żelazko on 13.01.2018.
//

#include <fstream>
#include <algorithms/BrutForceAlgorithm.hpp>
#include <algorithms/max_volume_first_algorithm/MaxVolumeFirstAlgorithm.hpp>
#include <algorithms/optimized_brut_force_algorithm/OptimizedBrutForceAlgorithm.h>
#include "ProgramInitializer.hpp"
#include "ProgramDecorator.h"

#include "boxes/boxes_provider/BoxesStandardStreamParser.h"
#include "boxes/boxes_provider/BoxesFileParser.h"
#include "boxes/boxes_provider/BoxesGenerator.hpp"
#include "result_printer/FileResultPrinter.h"

using namespace boxes_aficionado::program;
using namespace boxes_aficionado::boxes::boxes_provider;


ProgramInitializer::ProgramInitializer(int argc, const char **argv) :
		description_("Allowed options"),
		argc_(argc),
		argv_(argv) {

	description_.add_options()
			(command(HELP_CMD, "h").c_str(), "Show this help message")

			(command(INPUT_FILE_CMD, "i").c_str(), value<std::string>(&inputFile_), "Specify path to the input file")

			(command(OUTPUT_FILE_CMD, "o").c_str(), value<std::string>(&outputFile_), "Specify path to the output file")

			(command(EXECUTION_MODE_CMD, "m").c_str(), value<ExecutionMode_E>(&mode_)->required(),
			 "Choose execution mode (look size option):\n0 - generate problem,\n1 - generate and solve,\n2 - solve given problem\n")

			(command(PROBLEM_SIZE_CMD, "s").c_str(), value<units::size_t>(&problemSize_),
			 "Specifies generated problem size")

			(command(ALGORITHM_SELECTION, "a").c_str(),
			 value<algorithms::Algorithm_E>(&algorithm_)->default_value(algorithms::Algorithm_E::BRUT_FORCE, "0"),
			 "Select algorithm:\n0 - brut force(default),\n1 - max volume first\n2 - optimized brut forcels"
					 "");

}

std::unique_ptr<boxes_aficionado::program::Program> ProgramInitializer::getProgram() {

	std::unique_ptr<Program> program(new SimpleProgram);

	std::unique_ptr<BoxesProvider> boxesProvider(new BoxesStandardStreamParser());
	std::unique_ptr<result_printer::ResultPrinter> resultPrinter(new result_printer::ResultPrinter());

	try {
		store(parse_command_line(argc_, argv_, description_), variablesMap_);
		notify(variablesMap_);
	}
	catch (boost::program_options::required_option &e) {
		if (!variablesMap_.count(HELP_CMD))
			return std::make_unique<ErrorProgram>(std::move(program), e.what());
	}
	catch (std::logic_error &e) {
		program = std::make_unique<ErrorProgram>(std::move(program), e.what());
	}
//Check input arguments
	if (variablesMap_.count(HELP_CMD))
		return std::make_unique<HelpProgram>(std::move(program), description_);

	if (mode_ != ExecutionMode_E::solve && !variablesMap_.count(PROBLEM_SIZE_CMD)) {
		program = std::make_unique<ErrorProgram>(std::move(program), "Problem size was not specified");
	}

	if (mode_ != ExecutionMode_E::generateProblem && !variablesMap_.count(ALGORITHM_SELECTION)) {
		program = std::make_unique<ErrorProgram>(std::move(program), "Problem algorithm was not specified");
	}

//Initialize program
	if (!inputFile_.empty()) {
		if (mode_ == ExecutionMode_E::generateProblem)
			program = std::make_unique<ErrorProgram>(std::move(program),
			                                         "Specified input file despite execution mode : generate");
		else {
			std::ifstream input(inputFile_);
			if (input.is_open())
				boxesProvider = std::make_unique<BoxesFileParser>(input);
			else
				program = std::make_unique<ErrorProgram>(std::move(program), "Could not open specified input file");
		}
	}

	if (!outputFile_.empty()) {
		std::ofstream output(outputFile_);
		if (output.is_open())
			resultPrinter = std::make_unique<result_printer::FileResultPrinter>(output);
		else
			program = std::make_unique<ErrorProgram>(std::move(program), "Could not open specified output file");

	}

	if (dynamic_cast<SimpleProgram *>(program.get()) == nullptr) // Some errors occured
		return program;


//Create program instance
	switch (mode_) {
		case ExecutionMode_E::solve :
			program = std::make_unique<SolveProgram>(std::move(boxesProvider),
			                                         getAlgorithm(),
			                                         std::move(resultPrinter));
			break;
		case ExecutionMode_E::generateProblem :
			boxesProvider = std::make_unique<BoxesGenerator>(problemSize_);
			program = std::make_unique<GenerateBoxesProgram>(std::move(boxesProvider),
			                                                 std::move(resultPrinter));
			break;
		case ExecutionMode_E::generateAndSolve :
			boxesProvider = std::make_unique<BoxesGenerator>(problemSize_);
			program = std::make_unique<GenerateAndSolveProgram>(std::move(boxesProvider),
			                                                    getAlgorithm(),
			                                                    std::move(resultPrinter));
			break;
	}


	return program;

}

std::unique_ptr<algorithms::Algorithm> ProgramInitializer::getAlgorithm() const {

	switch (algorithm_) {
		case algorithms::Algorithm_E::BRUT_FORCE :
			return std::make_unique<algorithms::BrutForceAlgorithm>();
		case algorithms::Algorithm_E::MAX_VOLUME_FIRST:
			return std::make_unique<algorithms::max_volume_first_algorithm::MaxVolumeFirstAlgorithm>();
		case algorithms::Algorithm_E::BRUT_FORCE_OPT:
			return std::make_unique<algorithms::optimized_brut_force_algorithm::OptimizedBrutForceAlgorithm>();
		default:
			throw std::runtime_error("Invalid algorithm");
	}

}


std::string ProgramInitializer::command(std::string longCommand, std::string shortCommand) const {
	return longCommand + "," + shortCommand;
}


namespace boost {

	template<>
	boxes_aficionado::algorithms::Algorithm_E lexical_cast(const std::string &name) {

		using namespace boxes_aficionado::algorithms;

		static const std::map<const std::string, boxes_aficionado::algorithms::Algorithm_E> map = {
				{std::to_string(static_cast<int>(Algorithm_E::BRUT_FORCE)), Algorithm_E::BRUT_FORCE},
				{std::to_string(static_cast<int>(Algorithm_E::MAX_VOLUME_FIRST)), Algorithm_E::MAX_VOLUME_FIRST},
				{std::to_string(static_cast<int>(Algorithm_E::BRUT_FORCE_OPT)), Algorithm_E::BRUT_FORCE_OPT}

		};

		if (!map.count(name))
			throw std::logic_error("Could not find algorithm of value : " + name);

		return map.at(name);

	}

	template<>
	boxes_aficionado::program::ExecutionMode_E lexical_cast(const std::string &name) {

		static const std::map<const std::string, boxes_aficionado::program::ExecutionMode_E> map = {
				{std::to_string(
						static_cast<int>(boxes_aficionado::program::ExecutionMode_E::solve)),            boxes_aficionado::program::ExecutionMode_E::solve},
				{std::to_string(
						static_cast<int>(boxes_aficionado::program::ExecutionMode_E::generateAndSolve)), boxes_aficionado::program::ExecutionMode_E::generateAndSolve},
				{std::to_string(
						static_cast<int>(boxes_aficionado::program::ExecutionMode_E::generateProblem)),  boxes_aficionado::program::ExecutionMode_E::generateProblem}
		};

		if (!map.count(name))
			throw std::logic_error("Could not find mode of value : " + name);

		return map.at(name);
	}


}

