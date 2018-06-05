# Find the SDL2 library
#
# Defines:
#
# SDL2_FOUND
# SDL2_INCLUDE_DIRS
# SDL2_LIBRARIES
#
find_path (SDL2_INCLUDE_DIR "SDL2/SDL.h")
find_library (SDL2_LIBRARY NAMES SDL2 SDL2d)
find_library (SDL2main_LIBRARY NAMES SDL2main SDL2maind)

set (SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIR})
set (SDL2_LIBRARIES ${SDL2_LIBRARY} ${SDL2main_LIBRARY})

include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (SDL2 DEFAULT_MSG SDL2_INCLUDE_DIRS SDL2_LIBRARIES)
mark_as_advanced (SDL2_INCLUDE_DIRS SDL2_LIBRARIES)
