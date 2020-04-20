cmake_minimum_required(VERSION 3.15)
project(Schreier_Sims_algorithm)

set(CMAKE_CXX_STANDARD 14)

set(superflags "-Werror -Wall -Wextra -pedantic")

SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${superflags}")


include_directories("include")

add_executable(Schreier_Sims_algorithm src/Permutation.cpp src/Permutation_Cycle.cpp src/main.cpp)
add_executable(TestAlgorithm src/Permutation.cpp src/Permutation_Cycle.cpp test/test.cpp)
add_executable(FastTest src/main.cpp)