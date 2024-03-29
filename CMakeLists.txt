cmake_minimum_required(VERSION 3.9)
project(AAL_Boxes)

set(CMAKE_CXX_STANDARD 17)


find_package(Boost COMPONENTS program_options system REQUIRED)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message(${Boost_INCLUDE_DIRS})
endif ()

set(CMAKE_CXX_FLAGS "-Wall")

include_directories(${PROJECT_SOURCE_DIR}/sources/boxes_aficionado)

set(SOURCE_FILES sources/main.cpp sources/boxes_aficionado/boxes/Box.cpp sources/boxes_aficionado/algorithms/BrutForceAlgorithm.cpp sources/boxes_aficionado/algorithms/max_volume_first_algorithm/MaxVolumeFirstAlgorithm.cpp sources/boxes_aficionado/algorithms/max_volume_first_algorithm/MaxVolumeFirstAlgorithm.hpp sources/boxes_aficionado/boxes/boxes_provider/BoxesProvider.hpp sources/boxes_aficionado/program/ProgramInitializer.hpp sources/boxes_aficionado/program/SolveProgram.hpp sources/boxes_aficionado/boxes/boxes_provider/BoxesGenerator.hpp sources/boxes_aficionado/program/Program.h sources/boxes_aficionado/program/ProgramDecorator.h sources/boxes_aficionado/units.h sources/boxes_aficionado/RandomNumberGenerator.h sources/boxes_aficionado/boxes/boxes_provider/BoxesFileParser.h sources/boxes_aficionado/boxes/boxes_provider/BoxesStandardStreamParser.h sources/boxes_aficionado/program/result_printer/ResultPrinter.h sources/boxes_aficionado/program/ProgramInitializer.cpp sources/boxes_aficionado/algorithms/max_volume_first_algorithm/Vertex.cpp sources/boxes_aficionado/algorithms/max_volume_first_algorithm/Vertex.h sources/boxes_aficionado/algorithms/optimized_brut_force_algorithm/OptimizedBrutForceAlgorithm.cpp sources/boxes_aficionado/algorithms/optimized_brut_force_algorithm/OptimizedBrutForceAlgorithm.h)

add_executable(AAL_Boxes ${SOURCE_FILES})

if (Boost_FOUND)
    target_link_libraries(AAL_Boxes ${Boost_LIBRARIES})
endif ()