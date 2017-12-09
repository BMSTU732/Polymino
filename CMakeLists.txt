cmake_minimum_required(VERSION 3.2)
project(polymino)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Header files/)

set(SOURCE_FILES Source files/main.cpp Source files/Condition.cpp Source files/Coordinates.cpp
Source files/Data.cpp Source files/Errors.cpp Source files/Figures.cpp Source files/FiguresVariant.cpp Source files/Substring.cpp
Header files/Condition.hpp Header files/Coordinates.hpp Header files/Data.hpp Header files/Errors.hpp Header files/Figures.hpp
Header files/FiguresVariant.hpp Header files/Substring.hpp)
add_executable(polymino ${SOURCE_FILES})
