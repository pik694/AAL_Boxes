//
// Created by Piotr Żelazko on 13.11.2017.
//

#include "BrutForceAlgorithm.hpp"

using namespace boxes_aficionado;
using namespace boxes_aficionado::algorithms;

BrutForceAlgorithm::BrutForceAlgorithm():minVolume_(std::numeric_limits<uint64_t>::max()) {}

std::pair<std::vector<Box>, uint64_t> BrutForceAlgorithm::compute(std::vector<Box> boxes) {

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

uint64_t BrutForceAlgorithm::getVolume(const std::vector<Box> &boxes) const {

	uint64_t volume = 0;

	for (std::vector<Box>::const_iterator curr = boxes.begin(), next = ++boxes.begin(); next != boxes.end(); ++curr, ++next){

		if (!curr->fits(*next)) {
			volume += curr->getVolume();
		}

	}

	volume += (--boxes.end())->getVolume();

	return volume;
}



