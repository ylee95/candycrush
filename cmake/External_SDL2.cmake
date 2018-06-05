set (SDL2_url "https://www.libsdl.org/release/SDL2-2.0.8.tar.gz")

ExternalProject_Add (
    SDL2
    URL ${SDL2_url}
    CMAKE_CACHE_ARGS ${superbuild_DEFAULT_ARGS}
)
