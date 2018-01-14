//
// Created by Piotr Żelazko on 13.11.2017.
//

#ifndef AAL_BOXES_ALGORITHM_HPP
#define AAL_BOXES_ALGORITHM_HPP


#include <vector>
#include "boxes/Box.hpp"
#include "units.h"


using namespace boxes_aficionado;

namespace boxes_aficionado::algorithms {

	enum class Algorithm_E {
		BRUT_FORCE,
	};

	class Algorithm {
	public:
		using result_t = std::pair<std::vector<boxes::Box>, units::box_volume_t>;

		virtual result_t compute(std::vector<boxes::Box>) = 0;
	};
}


#endif //AAL_BOXES_ALGORITHM_HPP
