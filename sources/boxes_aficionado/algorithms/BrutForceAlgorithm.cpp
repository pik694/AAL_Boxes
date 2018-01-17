//
// Created by Piotr Żelazko on 13.11.2017.
//

#include "BrutForceAlgorithm.hpp"

using namespace boxes_aficionado;
using namespace boxes_aficionado::algorithms;


Algorithm::result_t BrutForceAlgorithm::compute(std::vector<boxes::Box> boxes) {

	std::sort(boxes.begin(), boxes.end());

	do{

		uint64_t volume = getVolume(boxes);

		if (volume < minVolume_) {
			minVolume_ = volume;
			bestPermutation_ = boxes;
		}

	}while(std::next_permutation(boxes.begin(), boxes.end()));

	return std::make_pair(bestPermutation_, minVolume_);
}


