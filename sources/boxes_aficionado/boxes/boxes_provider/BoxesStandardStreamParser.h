//
// Created by Piotr Żelazko on 13.01.2018.
//

#ifndef AAL_BOXES_BOXESSTANDARDSTREAMPARSER_H
#define AAL_BOXES_BOXESSTANDARDSTREAMPARSER_H

#include "BoxesProvider.hpp"

namespace boxes_aficionado {
	namespace boxes {
		namespace boxes_provider {
			class BoxesStandardStreamParser : public BoxesProvider {
			public:
				std::vector<Box> provideBoxes() override {
					units::size_t boxesCount;
					units::box_size_t x, y, z;
					std::vector<Box> boxes;

					std::cin >> boxesCount;
					for (units::size_t i = 0; i < boxesCount; ++i) {
						std::cin >> x >> y >> z;
						boxes.emplace_back(x, y, z);
					}

					return boxes;
				}
			};
		}
	}
}


#endif //AAL_BOXES_BOXESSTANDARDSTREAMPARSER_H
