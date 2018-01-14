//
// Created by Piotr Żelazko on 06.12.2017.
//

#ifndef AAL_BOXES_BOXESPROVIDER_HPP
#define AAL_BOXES_BOXESPROVIDER_HPP


#include <iostream>
#include <vector>

#include "boxes/Box.hpp"
#include "units.h"


namespace boxes_aficionado::boxes::boxes_provider {
	class BoxesProvider {
	public:

		virtual std::vector<Box> provideBoxes() = 0;

		virtual ~BoxesProvider() = default;
	};

}

#endif //AAL_BOXES_BOXESPROVIDER_HPP
