cmake_minimum_required(VERSION 3.9)
project(AAL_Boxes)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES sources/main.cpp sources/boxes_aficionado/Box.cpp sources/boxes_aficionado/algorithms/BrutForceAlgorithm.cpp sources/boxes_aficionado/algorithms/BoxesAficionadoAlgorithm.cpp sources/boxes_aficionado/algorithms/BoxesAficionadoAlgorithm.hpp)
add_executable(AAL_Boxes ${SOURCE_FILES})