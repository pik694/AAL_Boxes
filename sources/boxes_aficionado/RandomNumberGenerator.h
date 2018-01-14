//
// Created by Piotr Żelazko on 13.01.2018.
//

#ifndef AAL_BOXES_RANDOMNUMBERGENERATOR_H
#define AAL_BOXES_RANDOMNUMBERGENERATOR_H

#include <random>
#include "units.h"

namespace boxes_aficionado {

	template<units::box_size_t min, units::box_size_t max>
	struct RandomNumberGenerator {

		static units::box_size_t generateBoxSize() {

			static std::random_device randomDevice;
			static std::mt19937 generator(randomDevice());
			static std::uniform_int_distribution<> distribution(min, max);

			return distribution(generator);
		}
	};

}

#endif //AAL_BOXES_RANDOMNUMBERGENERATOR_H
