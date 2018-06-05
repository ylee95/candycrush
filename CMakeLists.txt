cmake_minimum_required (VERSION 3.8)
project (superbuild)

include (ExternalProject)

# Set module path.
set (
	CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake"
	${CMAKE_MODULE_PATH}
)

# Set prefix for external projects.
set (superbuild_INSTALL_PREFIX "${superbuild_BINARY_DIR}/prefix")
set (
	superbuild_DEFAULT_ARGS
	"-DCMAKE_PREFIX_PATH:PATH=${superbuild_INSTALL_PREFIX};${CMAKE_PREFIX_PATH}"
	"-DCMAKE_INSTALL_PREFIX:PATH=${superbuild_INSTALL_PREFIX}"
)

add_subdirectory (thirdparty)

include (External_tamagotchi)
