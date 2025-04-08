cmake_minimum_required(VERSION 3.24)
project(CP-2025)

set(CMAKE_CXX_STANDARD 20)

include_directories(lib/ src/ eigen/ json/)
add_executable(CP main.cpp lib/FileParser.cpp lib/QualityMetrics.cpp src/LeastSquares.cpp src/StatsMethod.cpp src/Huber.cpp src/Tukey.cpp)
