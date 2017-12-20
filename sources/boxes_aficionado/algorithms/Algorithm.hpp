//
// Created by Piotr Żelazko on 13.11.2017.
//

#ifndef AAL_BOXES_ALGORITHM_HPP
#define AAL_BOXES_ALGORITHM_HPP


#include <vector>
#include "../boxes/Box.hpp"


using namespace boxes_aficionado::boxes;

namespace boxes_aficionado::algorithms {

	class Algorithm {
	public:
		virtual std::pair<std::vector<Box>, uint64_t> compute(std::vector<Box>) = 0;
	};
}


#endif //AAL_BOXES_ALGORITHM_HPP
