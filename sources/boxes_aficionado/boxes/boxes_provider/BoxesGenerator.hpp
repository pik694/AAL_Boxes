//
// Created by Piotr Żelazko on 21.12.2017.
//

#ifndef AAL_BOXES_BOXESGENERATOR_HPP
#define AAL_BOXES_BOXESGENERATOR_HPP

#include <ctime>
#include <cstdlib>
#include "RandomNumberGenerator.h"

#include "BoxesProvider.hpp"


namespace boxes_aficionado::boxes::boxes_provider {
	class BoxesGenerator : public BoxesProvider {
	public:
		BoxesGenerator(int boxesCount) : boxesCount_(boxesCount) {}

		std::vector<Box> provideBoxes() override {

			std::vector<Box> boxes;

			for (int i = 0; i < boxesCount_; ++i) {
				boxes.emplace_back(
						randomNumberGenerator::generateBoxSize(),
						randomNumberGenerator::generateBoxSize(),
						randomNumberGenerator::generateBoxSize()
				);
			}
			return boxes;
		}

		virtual ~BoxesGenerator() = default;

	private:
		using numeric_limits_box_size = std::numeric_limits<units::box_size_t>;
		using randomNumberGenerator = RandomNumberGenerator<1, 100>;

		const units::size_t boxesCount_;
	};
}

#endif //AAL_BOXES_BOXESGENERATOR_HPP
