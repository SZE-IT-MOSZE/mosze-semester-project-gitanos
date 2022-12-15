cmake_minimum_required(VERSION 3.14)

set(This mosze_project)

project(${This})

set(CMAKE_CXX_STANDARD 14)

file(GLOB MY_PUBLIC_HEADERS
  "story/*.game"
)
file(COPY ${MY_PUBLIC_HEADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/game/story)

add_subdirectory(game)
add_subdirectory(gtest)