cmake_minimum_required (VERSION 3.8)
project (tamagotchi)

# Set module path.
set (
	CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake"
	${CMAKE_MODULE_PATH}
)

set (tamagotchi_deps_prefix "${tamagotchi_BINARY_DIR}/dep")
set (CMAKE_INSTALL_PREFIX ${tamagotchi_deps_prefix})
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

add_subdirectory (src)
