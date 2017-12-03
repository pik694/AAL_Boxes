#include <iostream>
#include "boxes_aficionado/Box.hpp"
#include "boxes_aficionado/algorithms/BrutForceAlgorithm.hpp"

using namespace boxes_aficionado;
using namespace boxes_aficionado::algorithms;

int main(int argc, char** argv) {


	std::vector<Box> boxes{{1, 1, 1},
	                       {4, 4, 10},
	                       {3, 3, 3},
	                       {2, 2, 4}};

	auto result = BrutForceAlgorithm().compute(boxes);

	std::for_each(result.first.begin(), result.first.end(), [](const Box &box) {
		std::cout << box.getID() << " ";
	});

	std::cout << std::endl << result.second << std::endl;

	return 0;
}
