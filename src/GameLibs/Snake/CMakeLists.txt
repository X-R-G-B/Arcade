cmake_minimum_required(VERSION 3.3)
project(
    Snake
    VERSION 1.0
    DESCRIPTION "Snake game lib"
    LANGUAGES CXX
)

add_library(arcade_snake SHARED)
target_sources(arcade_snake PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Snake.cpp"
)
