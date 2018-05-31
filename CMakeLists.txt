cmake_minimum_required (VERSION 2.8)
project (candycrush)

# SDL
add_subdirectory (SDL2-2.0.8 EXCLUDE_FROM_ALL)
target_include_directories (SDL2 PUBLIC $<BUILD_INTERFACE:${SDL2_SOURCE_DIR}/include>)

add_executable (candycrush main.cpp)
target_link_libraries (candycrush SDL2)
