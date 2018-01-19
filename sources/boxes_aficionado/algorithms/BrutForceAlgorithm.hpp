//
// Created by Piotr Żelazko on 13.11.2017.
//

#ifndef AAL_BOXES_BRUTFORCEALGORITHM_HPP
#define AAL_BOXES_BRUTFORCEALGORITHM_HPP

#include "Algorithm.hpp"

namespace boxes_aficionado::algorithms {
	class BrutForceAlgorithm : public Algorithm{
	public:

		BrutForceAlgorithm() = default;

		std::pair<std::vector<boxes::Box>, uint64_t> compute(std::vector<boxes::Box>) override;

		~BrutForceAlgorithm() override = default;
	};
}


#endif //AAL_BOXES_BRUTFORCEALGORITHM_HPP
