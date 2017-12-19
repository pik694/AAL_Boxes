//
// Created by Piotr Żelazko on 08.12.2017.
//

#ifndef AAL_BOXES_PROBLEMINSTANCE_HPP
#define AAL_BOXES_PROBLEMINSTANCE_HPP

#include "../algorithms/Algorithm.hpp"
#include "../BoxesProvider.hpp"

namespace boxes_aficionado {
	class ProblemInstance {
	public:
		ProblemInstance(std::ostream &outStream) : outStream_(outStream) {

		}

		virtual void run() = 0;


	protected:
		std::ostream &outStream_;
		std::unique_ptr<BoxesProvider> boxesProvider_;
		std::unique_ptr<algorithms::Algorithm> algorithm_;

	};
}


#endif //AAL_BOXES_PROBLEMINSTANCE_HPP
