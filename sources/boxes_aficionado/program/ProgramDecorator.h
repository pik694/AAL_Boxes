//
// Created by Piotr Żelazko on 13.01.2018.
//

#ifndef AAL_BOXES_PROBLEMDECORATOR_H
#define AAL_BOXES_PROBLEMDECORATOR_H

#include <memory>
#include <string>
#include <iostream>
#include <boost/program_options/options_description.hpp>

#include "Program.h"

namespace boxes_aficionado::program {
	class ProgramDecorator : public Program {
	public:
		explicit ProgramDecorator(std::unique_ptr<Program> problem) : decoratedProgram_(std::move(problem)) {}

		void run() override {
			decoratedProgram_->run();
		}

		~ProgramDecorator() override = default;

	private:
		std::unique_ptr<Program> decoratedProgram_;
	};

	class SimpleProgram : public Program {
	public:
		void run() override {}

		~SimpleProgram() override = default;
	};

	class ErrorProgram : public ProgramDecorator {
	public:
		ErrorProgram(std::unique_ptr<Program> program, std::string problem) :
				ProgramDecorator(std::move(program)),
				problem_(std::move(problem)) {}

		void run() override {

			std::cerr << problem_ << std::endl;
			ProgramDecorator::run();
		}

		virtual ~ErrorProgram() = default;

	private:

		const std::string problem_;
	};

	class HelpProgram : public ProgramDecorator {
	public:
		HelpProgram(std::unique_ptr<Program> program, boost::program_options::options_description description) :
				ProgramDecorator(std::move(program)),
				description_(std::move(description)) {}

		void run() override {
			std::cout << description_ << std::endl;
			ProgramDecorator::run();
		}

		virtual ~HelpProgram() = default;

	private:
		boost::program_options::options_description description_;
	};
}

#endif //AAL_BOXES_PROBLEMDECORATOR_H
