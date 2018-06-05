set (tamagotchi_source "${CMAKE_CURRENT_SOURCE_DIR}/tamagotchi")
set (tamagotchi_deps "SDL2")

ExternalProject_Add(
    tamagotchi
    SOURCE_DIR ${tamagotchi_source}
    CMAKE_CACHE_ARGS ${superbuild_DEFAULT_ARGS}
    DEPENDS ${tamagotchi_deps}
)
