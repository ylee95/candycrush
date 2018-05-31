cmake_minimum_required (VERSION 2.8)
project (candycrush)

# SDL
add_subdirectory (SDL2-2.0.8 EXCLUDE_FROM_ALL)
target_include_directories (SDL2 PUBLIC $<BUILD_INTERFACE:${SDL2_SOURCE_DIR}/include>)

set (
	SOURCE_FILES
	src/main.cpp
	src/sdlwrapper.cpp
)
add_executable (candycrush ${SOURCE_FILES})
target_include_directories (candycrush PRIVATE src)
target_link_libraries (candycrush SDL2)
