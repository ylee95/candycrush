# SDL
find_package (
	SDL2 REQUIRED CONFIG
	HINTS ${tamagotchi_deps_prefix}
)

# tamagotchi executable
# Find source files.
set (
	tamagotchi_source_files
	main.cpp
)
list (
	APPEND tamagotchi_source_files
	game.cpp
	sdlwrapper.cpp
)
list (
	APPEND tamagotchi_source_files
	util/time.cpp
)
add_executable (tamagotchi ${tamagotchi_source_files})
target_include_directories (tamagotchi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (tamagotchi SDL2::SDL2 SDL2::SDL2main)

# Install tamagotchi.
install (
	TARGETS tamagotchi
	RUNTIME DESTINATION bin
)
