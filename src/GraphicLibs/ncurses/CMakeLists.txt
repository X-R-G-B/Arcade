cmake_minimum_required(VERSION 3.3)
project(
    ncurses
    VERSION 1.0
    DESCRIPTION "ncurses graphical lib"
    LANGUAGES CXX
)

add_library(arcade_ncurses SHARED)
target_sources(arcade_ncurses PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Ncurses.cpp"
)
