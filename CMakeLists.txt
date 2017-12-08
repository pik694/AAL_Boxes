cmake_minimum_required(VERSION 3.9)
project(AAL_Boxes)

set(CMAKE_CXX_STANDARD 17)


find_package(Boost COMPONENTS program_options system REQUIRED)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message(${Boost_INCLUDE_DIRS})
endif ()


set(SOURCE_FILES sources/main.cpp sources/boxes_aficionado/Box.cpp sources/boxes_aficionado/algorithms/BrutForceAlgorithm.cpp sources/boxes_aficionado/algorithms/BoxesAficionadoAlgorithm.cpp sources/boxes_aficionado/algorithms/BoxesAficionadoAlgorithm.hpp sources/boxes_aficionado/BoxesProvider.hpp sources/boxes_aficionado/ProgramInitializer.hpp sources/boxes_aficionado/ProblemInstance.hpp)
add_executable(AAL_Boxes ${SOURCE_FILES})

if (Boost_FOUND)
    target_link_libraries(AAL_Boxes ${Boost_LIBRARIES})
endif ()