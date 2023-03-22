cmake_minimum_required(VERSION 3.3)
project(
    Arcade
    VERSION 1.0
    DESCRIPTION "A simple game engine"
    LANGUAGES CXX
)

set(CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
add_executable(arcade)
target_link_options(arcade PUBLIC -std=c++20)
add_subdirectory(src)

include(ExternalProject)
##############################################################################
# Game .so libs
ExternalProject_Add(
    GameLibs
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/GameLibs/"
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND ""
)
##############################################################################
# Graphics .so libs
ExternalProject_Add(
    GraphicLibs
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/GraphicLibs/"
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND ""
)
