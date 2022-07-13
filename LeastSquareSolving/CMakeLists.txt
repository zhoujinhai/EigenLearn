cmake_minimum_required(VERSION 3.10)

# set the project name
project(LeastSquareSolve VERSION 1.0)

# set verbose makefile
set(CMAKE_VERBOSE_MAKEFILE ON)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# eigen3
set(Eigen3_INCLUDE_DIR "D:/eigen")
include_directories(${Eigen3_INCLUDE_DIR})

# add the executable
message("current source dir: " ${PROJECT_BINARAY_DIR}, ${Tutorial_VERSION_MAJOR})
add_executable(${PROJECT_NAME} LeastSquareSolve.cpp)


