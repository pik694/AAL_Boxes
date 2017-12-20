//
// Created by Piotr Żelazko on 08.12.2017.
//

#ifndef AAL_BOXES_PROBLEMINSTANCE_HPP
#define AAL_BOXES_PROBLEMINSTANCE_HPP

#include "algorithms/Algorithm.hpp"
#include "boxes/BoxesProvider.hpp"

namespace boxes_aficionado {
	class ProblemInstance {
	public:
		ProblemInstance(std::ostream &outStream = std::cout) : outStream_(outStream) {

		}

		virtual ~ProblemInstance() {
			//TODO: close file
		}

		void run() {

			if (algorithm_) {
				auto result = algorithm_->compute(boxesProvider_->getBoxes());

				for (Box box : result.first) {
					outStream_ << box.getID() << " ";
				}

				outStream_ << std::endl << result.second << std::endl;
			} else {

				auto result = boxesProvider_->getBoxes();

				outStream_ << boxesProvider_->getBoxesNumber() << std::endl;

				for (Box box : result) {
					outStream_ << box << std::endl;
				}

			}
		}


	protected:
		std::ostream &outStream_;
		std::unique_ptr<BoxesProvider> boxesProvider_;
		std::unique_ptr<algorithms::Algorithm> algorithm_;

	};
}


#endif //AAL_BOXES_PROBLEMINSTANCE_HPP
