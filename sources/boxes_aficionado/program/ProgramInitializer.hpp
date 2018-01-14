//
// Created by Piotr Żelazko on 08.12.2017.
//

#ifndef AAL_BOXES_PROGRAMINITIALIZER_HPP
#define AAL_BOXES_PROGRAMINITIALIZER_HPP

#include <string>
#include <iostream>
#include <boost/program_options.hpp>


#include "Program.h"
#include "SolveProgram.hpp"
#include "algorithms/Algorithm.hpp"


using namespace boost::program_options;

namespace boxes_aficionado::program {

	enum class ExecutionMode_E {
		generateProblem,
		generateAndSolve,
		solve,
	};


	class ProgramInitializer {

	public:

		ProgramInitializer(int argc, const char **argv);

		std::unique_ptr<Program> getProgram();

		virtual ~ProgramInitializer() = default;

	private:

		std::string command(std::string longCommand, std::string shortCommand) const;

		std::unique_ptr<algorithms::Algorithm> getAlgorithm() const;

		using cstr_t = const char *;
		cstr_t HELP_CMD = "help";
		cstr_t INPUT_FILE_CMD = "in";
		cstr_t OUTPUT_FILE_CMD = "out";
		cstr_t EXECUTION_MODE_CMD = "mode";
		cstr_t PROBLEM_SIZE_CMD = "size";
		cstr_t ALGORITHM_SELECTION = "algorithm";

		options_description description_;
		variables_map variablesMap_;

		int argc_;
		const char **argv_;

		std::string inputFile_;
		std::string outputFile_;
		ExecutionMode_E mode_;
		algorithms::Algorithm_E algorithm_;
		units::size_t problemSize_;

	};

}

namespace boost {

	template<>
	boxes_aficionado::algorithms::Algorithm_E lexical_cast(const std::string &name);
	template<>
	boxes_aficionado::program::ExecutionMode_E lexical_cast(const std::string &name);

}

#endif //AAL_BOXES_PROGRAMINITIALIZER_HPP
