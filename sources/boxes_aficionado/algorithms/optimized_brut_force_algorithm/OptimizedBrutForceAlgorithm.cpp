//
// Created by Piotr Żelazko on 17.01.2018.
//

#include "OptimizedBrutForceAlgorithm.h"
#include "boxes/Box.hpp"

using namespace boxes_aficionado::algorithms::optimized_brut_force_algorithm;

algorithms::Algorithm::result_t OptimizedBrutForceAlgorithm::compute(std::vector<boxes::Box> boxes) {

	std::vector<int> parents(boxes.size());
	std::vector<std::vector<int>> children(boxes.size());
	std::vector<bool> packed (boxes.size(), false);

	for(size_t i = 0; i < boxes.size(); ++i){
		for(size_t j = i + 1; j < boxes.size(); ++j){
			if (boxes.at(i).fits(boxes.at(j))){
				children.at(j).push_back(i);
			} else if (boxes.at(j).fits(boxes.at(i))){
				children.at(i).push_back(j);
			}
		}
	}

	for (int i = 0; i < boxes.size(); ++i){
		if (children.at(i).size() == 1){
			packed.at(children.at(i).at(0)) = true;
			parents.at(children.at(i).at(0)) = i;
		}
	}

	std::vector<boxes::Box> tmp;

	for (int i = 0; i < boxes.size(); ++i){
		if (!packed.at(i)){
			tmp.push_back(boxes.at(i));
		}
	}

	auto brutResult = BrutForceAlgorithm::compute(tmp);
	auto resultVect = std::move(brutResult.first);

	bool done;
	do{
		done = true;
		for (int i = 0; i < boxes.size(); ++i){
			if (packed.at(i)){
				done = false;
				for (auto iterator = resultVect.begin(); iterator != resultVect.end(); ++iterator){
					if (iterator->getID() == parents.at(i)){
						resultVect.insert(iterator, boxes.at(i));
						packed.at(i) = false;
						break;
					}
				}
			}
		}

	}while (!done);

	return std::make_pair(resultVect, getVolume(resultVect));

}
