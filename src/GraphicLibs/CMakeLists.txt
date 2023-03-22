cmake_minimum_required(VERSION 3.3)
project(
    GraphicLibs
    VERSION 1.0
    DESCRIPTION "Some graphical libs"
    LANGUAGES CXX
)

include(ExternalProject)
ExternalProject_Add(
    SDL,
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SDL"
)
ExternalProject_Add(
    SFML,
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML"
)
ExternalProject_Add(
    ncurses,
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ncurses"
)
