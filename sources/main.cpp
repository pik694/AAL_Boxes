#include <iostream>
#include "boxes_aficionado/Box.hpp"
#include "boxes_aficionado/algorithms/BrutForceAlgorithm.hpp"

using namespace boxes_aficionado;
using namespace boxes_aficionado::algorithms;

int main(int argc, char** argv) {


	std::vector<Box> boxes = {{1,2,3}, {4,2,3}, };

	std::cout << "Min : "  << BrutForceAlgorithm().compute(boxes) << std::endl;

	return 0;
}
