//
// Created by Piotr Żelazko on 02.12.2017.
//

#include "BoxesAficionadoAlgorithm.hpp"

using namespace boxes_aficionado;
using namespace algorithms;


Algorithm::result_t BoxesAficionadoAlgorithm::compute(std::vector<boxes::Box> boxes) {
	return std::make_pair(std::vector<boxes::Box>(), std::numeric_limits<units::box_volume_t>::max());
}
