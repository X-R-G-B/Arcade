cmake_minimum_required(VERSION 3.3)
project(
    Nibleur
    VERSION 1.0
    DESCRIPTION "Nibleur game lib"
    LANGUAGES CXX
)
add_library(arcade_nibbler SHARED)
target_sources(arcade_nibbler PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Nibleur.cpp"
)
