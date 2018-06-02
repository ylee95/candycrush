cmake_minimum_required (VERSION 2.8)
project (tamagotchi)

# SDL
add_subdirectory (SDL2-2.0.8 EXCLUDE_FROM_ALL)
target_include_directories (SDL2 PUBLIC $<BUILD_INTERFACE:${SDL2_SOURCE_DIR}/include>)

set (
	SOURCE_FILES
	src/game.cpp
	src/main.cpp
	src/sdlwrapper.cpp
)
add_executable (tamagotchi ${SOURCE_FILES})
target_include_directories (tamagotchi PRIVATE src)
target_link_libraries (tamagotchi SDL2)
