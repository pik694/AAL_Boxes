//
// Created by Piotr Żelazko on 13.11.2017.
//

#ifndef AAL_BOXES_ALGORITHM_HPP
#define AAL_BOXES_ALGORITHM_HPP


#include <vector>
#include "../Box.hpp"

namespace boxes_aficionado::algorithms {

	using namespace boxes_aficionado;

	class Algorithm {
		virtual int compute(std::vector<Box>) = 0;
	};
}


#endif //AAL_BOXES_ALGORITHM_HPP
