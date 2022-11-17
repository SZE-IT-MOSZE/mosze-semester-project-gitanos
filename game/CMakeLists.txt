cmake_minimum_required(VERSION 3.14)

set(This game)

project(${This})

set(CMAKE_CXX_STANDARD 11)

set (Headers
	functions.h
	classes.h
)

set (Sources
	game.cpp
)

add_executable(${This} ${Sources} ${Headers})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${This})