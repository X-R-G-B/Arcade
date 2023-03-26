cmake_minimum_required(VERSION 3.3)
project(
    SFML
    VERSION 1.0
    DESCRIPTION "SFML graphical lib"
    LANGUAGES CXX
)

target_include_directories(arcade PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../Arcade/ECS/"
)

add_library(arcade_sfml SHARED)
target_sources(arcade_sfml PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/SFML.cpp"
)
