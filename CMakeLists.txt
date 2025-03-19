cmake_minimum_required(VERSION 3.24)
project(cp_back)

set(CMAKE_CXX_STANDARD 20)

add_executable(cp_back main.cpp FileParser.cpp LeastSquares.cpp)
