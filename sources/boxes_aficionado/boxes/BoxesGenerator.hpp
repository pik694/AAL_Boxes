//
// Created by Piotr Żelazko on 21.12.2017.
//

#ifndef AAL_BOXES_BOXESGENERATOR_HPP
#define AAL_BOXES_BOXESGENERATOR_HPP

#include <ctime>
#include <cstdlib>

#include "BoxesProvider.hpp"


namespace boxes_aficionado::boxes {
	class BoxesGenerator : public BoxesProvider {
	public:
		BoxesGenerator(int boxesNumber) : BoxesProvider(boxesNumber) {
			std::srand(std::time(nullptr));
		}

	private:
		virtual Box createBox() {

			uint16_t x = std::rand() % std::numeric_limits<uint16_t>::max();
			uint16_t y = std::rand() % std::numeric_limits<uint16_t>::max();
			uint16_t z = std::rand() % std::numeric_limits<uint16_t>::max();

			return Box(x, y, z);

		}
	};
}

#endif //AAL_BOXES_BOXESGENERATOR_HPP
