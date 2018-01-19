#include "boxes_aficionado/boxes/Box.hpp"
#include "boxes_aficionado/algorithms/BrutForceAlgorithm.hpp"
#include "boxes_aficionado/program/ProgramInitializer.hpp"


using namespace boxes_aficionado::program;
using namespace boxes_aficionado::algorithms;

int main(int argc, const char **argv) {

	ProgramInitializer initializer(argc, argv);

	initializer.getProgram()->run();

	return 0;
}

