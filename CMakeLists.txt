cmake_minimum_required (VERSION 3.8)
project (tamagotchi)

# Set module path.
set (
	CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake"
	${CMAKE_MODULE_PATH}
)

set (tamagotchi_deps_prefix "${tamagotchi_BINARY_DIR}/dep")
list (APPEND CMAKE_PREFIX_PATH ${tamagotchi_deps_prefix})

# Install dependencies.
configure_file (
	CMakeLists.txt.in
	"${tamagotchi_deps_prefix}/CMakeLists.txt"
	COPYONLY
)
execute_process (
	COMMAND ${CMAKE_COMMAND} ${tamagotchi_deps_prefix}
	WORKING_DIRECTORY ${tamagotchi_deps_prefix}
)
execute_process (
	COMMAND ${CMAKE_COMMAND} --build ${tamagotchi_deps_prefix}
	WORKING_DIRECTORY ${tamagotchi_deps_prefix}
)

find_package (SDL2 REQUIRED)

set (
	tamagotchi_source_files
	src/game.cpp
	src/main.cpp
	src/sdlwrapper.cpp
)
add_executable (tamagotchi ${tamagotchi_source_files})
target_include_directories (tamagotchi PRIVATE src ${SDL2_INCLUDE_DIRS})
target_link_libraries (tamagotchi ${SDL2_LIBRARIES})
