//
// Created by Piotr Żelazko on 08.12.2017.
//

#ifndef AAL_BOXES_PROBLEMINSTANCE_HPP
#define AAL_BOXES_PROBLEMINSTANCE_HPP

#include "Program.h"
#include "algorithms/Algorithm.hpp"
#include "boxes/boxes_provider/BoxesProvider.hpp"
#include "program/result_printer/ResultPrinter.h"


namespace boxes_aficionado {
	namespace program {
		class SolveProgram : public Program {
		public:

			SolveProgram(std::unique_ptr<boxes::boxes_provider::BoxesProvider> boxesProvider,
			             std::unique_ptr<algorithms::Algorithm> algorithm,
			             std::unique_ptr<program::result_printer::ResultPrinter> resultPrinter) :
					boxesProvider_(std::move(boxesProvider)),
					algorithm_(std::move(algorithm)),
					resultPrinter_(std::move(resultPrinter)) {}


			virtual ~SolveProgram() = default;

			void run() {

				auto boxes = boxesProvider_->provideBoxes();
				auto result = algorithm_->compute(boxes);
				resultPrinter_->printResult(result);
			}


		protected:
			std::unique_ptr<boxes::boxes_provider::BoxesProvider> boxesProvider_;
			std::unique_ptr<algorithms::Algorithm> algorithm_;
			std::unique_ptr<program::result_printer::ResultPrinter> resultPrinter_;

		};


		class GenerateBoxesProgram : public Program {
		public:

			GenerateBoxesProgram(std::unique_ptr<boxes::boxes_provider::BoxesProvider> boxesProvider,
			                     std::unique_ptr<program::result_printer::ResultPrinter> resultPrinter) :
					boxesProvider_(std::move(boxesProvider)),
					resultPrinter_(std::move(resultPrinter)) {}


			virtual ~GenerateBoxesProgram() = default;

			void run() {

				auto boxes = boxesProvider_->provideBoxes();
				resultPrinter_->printBoxes(boxes);
			}


		protected:
			std::unique_ptr<boxes::boxes_provider::BoxesProvider> boxesProvider_;
			std::unique_ptr<program::result_printer::ResultPrinter> resultPrinter_;

		};

		class GenerateAndSolveProgram : public Program {
		public:

			GenerateAndSolveProgram(std::unique_ptr<boxes::boxes_provider::BoxesProvider> boxesProvider,
			                        std::unique_ptr<algorithms::Algorithm> algorithm,
			                        std::unique_ptr<program::result_printer::ResultPrinter> resultPrinter) :
					boxesProvider_(std::move(boxesProvider)),
					algorithm_(std::move(algorithm)),
					resultPrinter_(std::move(resultPrinter)) {}


			virtual ~GenerateAndSolveProgram() = default;

			void run() {

				auto boxes = boxesProvider_->provideBoxes();
				resultPrinter_->printBoxes(boxes);
				auto result = algorithm_->compute(boxes);
				resultPrinter_->printResult(result);
			}


		protected:
			std::unique_ptr<boxes::boxes_provider::BoxesProvider> boxesProvider_;
			std::unique_ptr<algorithms::Algorithm> algorithm_;
			std::unique_ptr<program::result_printer::ResultPrinter> resultPrinter_;

		};
	}
}


#endif //AAL_BOXES_PROBLEMINSTANCE_HPP
