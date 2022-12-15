cmake_minimum_required(VERSION 3.14)

set(This mosze_project)

project(${This})

set(CMAKE_CXX_STANDARD 14)



add_subdirectory(game)
add_subdirectory(gtest)