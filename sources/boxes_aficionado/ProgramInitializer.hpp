//
// Created by Piotr Żelazko on 08.12.2017.
//

#ifndef AAL_BOXES_PROGRAMINITIALIZER_HPP
#define AAL_BOXES_PROGRAMINITIALIZER_HPP

#include <string>
#include <iostream>
#include <boost/program_options.hpp>

#include "problem_instance/ProblemInstance.hpp"

using namespace boost::program_options;


namespace boxes_aficionado {

	enum class ExecutionMode_e {
		generateProblem, generateAndSolve, solve,
	};

	class ProgramInitializer {
		using cstr_t = const char *;

	public:

		ProgramInitializer() : description_("Allowed options") {
			description_.add_options()
					(command(HELP_CMD, "h"), "Show this help message")
					(command(VERSION_CMD, "v"), "Print version info")
					(command(INPUT_FILE_CMD, "i"), value<std::string>(), "Specify path to the input file")
					(command(OUTPUT_FILE_CMD, "o"), value<std::string>(), "Specify path to the output file")
					(command(EXECUTION_MODE_CMD, "m"), value<int>(), "Choose execution mode. 0 - generate problem, ")
					(command(PROBLEM_SIZE_CMD, "s"), value<int>(), "Specifies generated problem size")
					(command(ALGORITHM_SELECTION, "a"), value<std::shared_ptr<algorithms::Algorithm>>(),
					 "Select algorithm. 0 - brut force, 1 - heuristic, ");

		}

		std::unique_ptr<ProblemInstance> parse(int argc, const char **argv) {

			store(parse_command_line(argc, argv, description_), variablesMap_);
			notify(variablesMap_);

			if (variablesMap_.count(HELP_CMD)) {

				variablesMap_

						exit(0);
			}

			//return std::make_unique<ProblemInstance>();
		}


	private:
		cstr_t HELP_CMD = "help";
		cstr_t VERSION_CMD = "version";
		cstr_t INPUT_FILE_CMD = "in";
		cstr_t OUTPUT_FILE_CMD = "out";
		cstr_t EXECUTION_MODE_CMD = "mode";
		cstr_t PROBLEM_SIZE_CMD = "size";
		cstr_t ALGORITHM_SELECTION = "algorithm";

		options_description description_;
		variables_map variablesMap_;


		const char *command(std::string longCommand, std::string shortCommand) const {
			return (longCommand + "," + shortCommand).c_str();
		};

	};
}

namespace boost {

	template<>
	std::shared_ptr<algorithms::Algorithm> lexical_cast(const std::string &name) {

		return std::make_shared<algorithms::BrutForceAlgorithm>();

	}

}


#endif //AAL_BOXES_PROGRAMINITIALIZER_HPP
