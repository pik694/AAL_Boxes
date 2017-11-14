//
// Created by Piotr Żelazko on 13.11.2017.
//

#include "BrutForceAlgorithm.hpp"

using namespace boxes_aficionado;
using namespace boxes_aficionado::algorithms;

BrutForceAlgorithm::BrutForceAlgorithm():minVolume_(std::numeric_limits<uint64_t>::max()) {}

int BrutForceAlgorithm::compute(std::vector<Box> boxes){

	std::sort(boxes.begin(), boxes.end());

	do{

		minVolume_ = std::min(minVolume_, getVolume(boxes));

	}while(std::next_permutation(boxes.begin(), boxes.end()));

	return minVolume_;
}

uint64_t BrutForceAlgorithm::getVolume(const std::vector<Box>& boxes) {

	uint64_t volume = 0;

	for (std::vector<Box>::const_iterator curr = boxes.begin(), next = ++boxes.begin(); next != boxes.end(); ++curr, ++next){

		if (!next->fits(*curr)){
			volume += next->getVolume();
		}

	}

	volume += boxes.begin()->getVolume();

	return volume;
}



