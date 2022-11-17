cmake_minimum_required(VERSION 3.14)

set(This mosze_project)

project(${This})

set(CMAKE_CXX_STANDARD 11)

enable_testing()

file(GLOB MY_PUBLIC_HEADERS
  "story/*.game"
)
file(COPY ${MY_PUBLIC_HEADERS} DESTINATION story)

add_subdirectory(game)
add_subdirectory(gtest)