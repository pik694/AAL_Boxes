//
// Created by Piotr Żelazko on 13.01.2018.
//

#ifndef AAL_BOXES_BOXESFILEPARSER_H
#define AAL_BOXES_BOXESFILEPARSER_H

#include <fstream>
#include <boost/range/irange.hpp>
#include "BoxesProvider.hpp"


namespace boxes_aficionado {
	namespace boxes {
		namespace boxes_provider {
			class BoxesFileParser : public BoxesProvider {
			public:

				explicit BoxesFileParser(std::ifstream &inFile) : inFile_(std::move(inFile)) {
					if (!inFile_.is_open()) throw std::runtime_error("Could not open input file");
				}

				std::vector<Box> provideBoxes() override {
					units::size_t boxesCount;
					units::box_size_t x, y, z;
					std::vector<Box> boxes;

					inFile_ >> boxesCount;
					for (units::size_t i = 0; i < boxesCount; ++i) {
						inFile_ >> x >> y >> z;
						boxes.emplace_back(x, y, z);
					}

					return boxes;
				}

				virtual ~BoxesFileParser() {
					inFile_.close();
				}

			private:
				std::ifstream inFile_;
			};
		}
	}
}


#endif //AAL_BOXES_BOXESFILEPARSER_H


//TODO: alter includes