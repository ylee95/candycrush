cmake_minimum_required (VERSION 3.8)
project (tamagotchi)

# Set module path.
set (
	CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake"
	${CMAKE_MODULE_PATH}
)

find_package (SDL2 REQUIRED)

# Source files for tamagotchi.
set (
    tamagotchi_source_files
    game.cpp
    main.cpp
    sdlwrapper.cpp
)

add_executable (tamagotchi ${tamagotchi_source_files})
target_include_directories (tamagotchi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})
target_link_libraries (tamagotchi PRIVATE ${SDL2_LIBRARIES})

# Install tamagotchi executable.
install (
    TARGETS tamagotchi
    RUNTIME DESTINATION bin
)
