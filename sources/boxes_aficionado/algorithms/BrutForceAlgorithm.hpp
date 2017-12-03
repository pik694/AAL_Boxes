//
// Created by Piotr Żelazko on 13.11.2017.
//

#ifndef AAL_BOXES_BRUTFORCEALGORITHM_HPP
#define AAL_BOXES_BRUTFORCEALGORITHM_HPP

#include "Algorithm.hpp"

namespace boxes_aficionado::algorithms {
	class BrutForceAlgorithm : public Algorithm{
	public:

		BrutForceAlgorithm();

		virtual std::pair<std::vector<Box>, uint64_t> compute(std::vector<Box>) override;
	private:


		uint64_t getVolume(const std::vector<Box> &) const;

		uint64_t minVolume_;
		std::vector<Box> bestPermutation_;
	};
}


#endif //AAL_BOXES_BRUTFORCEALGORITHM_HPP
