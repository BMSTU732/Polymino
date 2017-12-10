cmake_minimum_required(VERSION 3.2)
project(Polymino)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Header files/)

set(SOURCE_FILES Source files/Condition.cpp Header files/Condition.hpp Source files/Coordinates.cpp Header files/Coordinates.hpp
Source files/Data.cpp Header files/Data.hpp Source files/Errors.cpp Header files/Errors.hpp Source files/Figures.cpp Header files/Figures.hpp 
Source files/FiguresVariant.cpp Header files/FiguresVariant.hpp Source files/Substring.cpp Header files/Substring.hpp)
    
add_executable(Polymino ${SOURCE_FILES} Source files/main.cpp)
