//
// Created by Piotr Żelazko on 08.12.2017.
//

#ifndef AAL_BOXES_PROGRAMINITIALIZER_HPP
#define AAL_BOXES_PROGRAMINITIALIZER_HPP

struct {
	unsigned int MINOR = 1;
	unsigned int MAJOR = 0;
} APP_VERSION;

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

			std::string str = std::string(command(HELP_CMD, "h"));

			description_.add_options()
					(command(HELP_CMD, "h").c_str(), "Show this help message")
					(command(VERSION_CMD, "v").c_str(), "Print version info")
					(command(INPUT_FILE_CMD, "i").c_str(), value<std::string>(), "Specify path to the input file")
					(command(OUTPUT_FILE_CMD, "o").c_str(), value<std::string>(), "Specify path to the output file")
					(command(EXECUTION_MODE_CMD, "m").c_str(), value<int>(),
					 "Choose execution mode (look size option):\n0 - generate problem,\n1 - generate and solve,\n2 - solve given problem\n")
					(command(PROBLEM_SIZE_CMD, "s").c_str(), value<int>(), "Specifies generated problem size")
					(command(ALGORITHM_SELECTION, "a").c_str(), value<std::shared_ptr<algorithms::Algorithm>>(),
					 "Select algorithm:\n0 - brut force,\n1 - heuristic.");

		}

		/*std::unique_ptr<ProblemInstance>*/ void parse(int argc, const char **argv) {

			store(parse_command_line(argc, argv, description_), variablesMap_);
			notify(variablesMap_);

			if (variablesMap_.count(HELP_CMD)) {
				std::cout << description_ << std::endl;
				exit(0);
			}

			if (variablesMap_.count(VERSION_CMD)) {
				std::cout << "Version : " << APP_VERSION.MAJOR << "." << APP_VERSION.MINOR << std::endl;
				exit(0);
			}

			if (!variablesMap_.count(EXECUTION_MODE_CMD)) {
				std::cerr << "Provide execution mode!" << std::endl;
				exit(1);
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


		std::string command(std::string longCommand, std::string shortCommand) const {
			return (longCommand + "," + shortCommand);
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
