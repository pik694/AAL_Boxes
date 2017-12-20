//
// Created by Piotr Żelazko on 06.12.2017.
//

#ifndef AAL_BOXES_BOXESPROVIDER_HPP
#define AAL_BOXES_BOXESPROVIDER_HPP

#include "Box.hpp"
#include <iostream>
#include <vector>

namespace boxes_aficionado::boxes {
	class BoxesProvider {
	public:

		BoxesProvider(int boxesNumber, std::istream &istream = std::cin) : istream_(istream),
		                                                                   boxesNumber_(boxesNumber) {}

		virtual ~BoxesProvider() {

			//TODO : close file
		}

		int getBoxesNumber() {
			return boxesNumber_;
		}

		std::vector<Box> getBoxes() {

			std::vector<Box> boxes;

			for (int i = 0; i < boxesNumber_; ++i) {
				boxes.push_back(createBox());
			}

			return boxes;

		}


	private:

		virtual Box createBox() {

			uint16_t x, y, z;
			istream_ >> x >> y >> z;
			return Box(x, y, z);

		}

		std::istream &istream_;
		const int boxesNumber_;

	};
}

#endif //AAL_BOXES_BOXESPROVIDER_HPP
