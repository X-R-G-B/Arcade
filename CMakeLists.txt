cmake_minimum_required(VERSION 3.3)
project(
    Arcade
    VERSION 1.0
    DESCRIPTION "A simple game engine"
    LANGUAGES CXX
)

add_executable(arcade)
add_subdirectory(src)

include(ExternalProject)
##############################################################################
# Game .so libs
ExternalProject_Add(
    GameLibs
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/GameLibs/"
)
##############################################################################
# Graphics .so libs
ExternalProject_Add(
    GraphicLibs
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/GraphicLibs/"
)
