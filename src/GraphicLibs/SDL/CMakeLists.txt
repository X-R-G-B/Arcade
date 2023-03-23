cmake_minimum_required(VERSION 3.3)
project(
    SDL
    VERSION 1.0
    DESCRIPTION "SDL graphical lib"
    LANGUAGES CXX
)

add_library(arcade_sdl2 SHARED)
target_sources(arcade_sdl2 PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/SDL.cpp"
)
