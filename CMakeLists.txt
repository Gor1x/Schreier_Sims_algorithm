cmake_minimum_required(VERSION 3.15)
project(Schreier_Sims_algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories("include")

add_executable(Schreier_Sims_algorithm src/Permutation.cpp src/main.cpp)
add_executable(TestAlgorithm src/Permutation.cpp test/test.cpp)