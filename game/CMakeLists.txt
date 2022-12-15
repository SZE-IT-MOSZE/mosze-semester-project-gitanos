cmake_minimum_required(VERSION 3.14)

set(This game)

project(${This})

set(CMAKE_CXX_STANDARD 14)
set (Headers
	functions.h
	classes.h
)

set (Sources
	game.cpp
)

add_executable(${This} ${Sources} ${Headers})
# Sztori fájlok kijelölése
set(StoryFiles "story/*.game")
# A sztori fájlokon végigiterálás és másolás
foreach(storyfile ${StoryFiles})
    # Iterált fájl másolása
    add_custom_command(TARGET ${This} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E
        copy ${CMAKE_SOURCE_DIR}/${storyfile} ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${storyfile}
    )
    
endforeach(storyfile)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${This})