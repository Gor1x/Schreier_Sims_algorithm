cmake_minimum_required(VERSION 3.15)
project(Schreier_Sims_algorithm)

set(CMAKE_CXX_STANDARD 14)
set(MPIR_LIB /home/egor/Cpp_libraries/mpir)

set(SUPERS "-Werror -Wall -Wextra -pedantic -lmpirxx -lmpir -lgmpxx -lgmp")

SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${SUPERS}")

find_path(USRPATH /usr/local/lib)
find_path(INCLUDEPATH /usr/local/include)

include_directories(Schreier_Sims_algorithm "include")
include_directories(Schreier_Sims_algorithm /usr/local/lib)
include_directories(Schreier_Sims_algorithm /usr/local/include)

add_executable(Schreier_Sims_algorithm src/Permutation.cpp src/Permutation_Cycle.cpp src/main.cpp src/SchreierTree.cpp include/SchreierTree.h src/SchreierStabChain.cpp include/SchreierStabChain.h)
add_executable(TestAlgorithm src/Permutation.cpp src/Permutation_Cycle.cpp test/SchreierSimsTest.cpp test/Test.cpp test/test.cpp src/SchreierTree.cpp include/SchreierTree.h src/SchreierStabChain.cpp include/SchreierStabChain.h)
add_executable(FastTest src/main.cpp src/Permutation.cpp include/Permutation.h src/Permutation_Cycle.cpp src/SchreierTree.cpp include/SchreierTree.h src/SchreierStabChain.cpp include/SchreierStabChain.h src/BigInteger.cpp include/BigInteger.hpp)
add_executable(GroupTask my_task/task.cpp src/Permutation.cpp include/Permutation.h src/Permutation_Cycle.cpp src/SchreierTree.cpp include/SchreierTree.h src/SchreierStabChain.cpp include/SchreierStabChain.h)

find_library(MPIRXX libmpirxx /usr/local/lib)
find_library(GMPXX libgmpxx /usr/local/lib)
find_library(MPIR libmpir /usr/local/lib)
find_library(GMP libgmp /usr/local/lib)

find_library(gmp REQUIRED)
target_link_libraries(Schreier_Sims_algorithm gmp libgmp)

target_link_libraries(Schreier_Sims_algorithm libmpirxx libgmpxx libmpir libgmp)