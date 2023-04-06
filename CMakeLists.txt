cmake_minimum_required(VERSION 3.13)
project(
    Arcade
    VERSION 1.0
    DESCRIPTION "A simple Arcade"
    LANGUAGES CXX
)

##############################################################################
# arcade binary
add_executable(arcade)
set_target_properties(arcade PROPERTIES
    CXX_STANDARD 20
    COMPILE_FLAGS "-fno-gnu-unique"
)
##############################################################################
# arcade main menu
add_library(arcade_menu_main SHARED)
set_target_properties(arcade_menu_main PROPERTIES
    CXX_STANDARD 20
    COMPILE_FLAGS "-fno-gnu-unique"
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/menu/"
)
##############################################################################
# Game .so libs
add_library(arcade_nibbler SHARED)
set_target_properties(arcade_nibbler PROPERTIES
    CXX_STANDARD 20
    COMPILE_FLAGS "-fno-gnu-unique"
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
add_library(arcade_snake SHARED)
set_target_properties(arcade_snake PROPERTIES
    CXX_STANDARD 20
    COMPILE_FLAGS "-fno-gnu-unique"
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
##############################################################################
# Graphics .so libs
add_library(arcade_ncurses SHARED)
set_target_properties(arcade_ncurses PROPERTIES
    CXX_STANDARD 20
    COMPILE_FLAGS "-fno-gnu-unique"
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
add_library(arcade_sdl2 SHARED)
set_target_properties(arcade_sdl2 PROPERTIES
    CXX_STANDARD 20
    COMPILE_FLAGS "-fno-gnu-unique"
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
add_library(arcade_sfml SHARED)
set_target_properties(arcade_sfml PROPERTIES
    CXX_STANDARD 20
    COMPILE_FLAGS "-fno-gnu-unique"
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

add_subdirectory(src)
