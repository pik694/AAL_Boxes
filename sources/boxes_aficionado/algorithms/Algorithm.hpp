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
		MAX_VOLUME_FIRST,
		BRUT_FORCE_OPT
	};

	class Algorithm {
	public:
		using result_t = std::pair<std::vector<boxes::Box>, units::box_volume_t>;

		Algorithm() : minVolume_(std::numeric_limits<units::box_volume_t>::max()) {}

		virtual result_t compute(std::vector<boxes::Box>) = 0;

		virtual ~Algorithm() = default;


	protected:

		units::box_volume_t getVolume(const std::vector<boxes::Box> &boxes) const {
			uint64_t volume = 0;

			for (auto curr = boxes.cbegin(), next = ++boxes.cbegin(); next != boxes.cend(); ++curr, ++next) {

				if (!curr->fits(*next)) {
					volume += curr->getVolume();
				}

			}

			volume += (--boxes.end())->getVolume();

			return volume;
		}


		units::box_volume_t minVolume_;
		std::vector<boxes::Box> bestPermutation_;


	};
}


#endif //AAL_BOXES_ALGORITHM_HPP
