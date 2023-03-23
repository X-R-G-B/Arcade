cmake_minimum_required(VERSION 3.3)
project(
    SFML
    VERSION 1.0
    DESCRIPTION "SFML graphical lib"
    LANGUAGES CXX
)

add_library(arcade_sfml SHARED)
target_sources(arcade_sfml PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/SFML.cpp"
)
