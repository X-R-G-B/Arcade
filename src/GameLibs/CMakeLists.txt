cmake_minimum_required(VERSION 3.3)
project(
    GameLibs
    VERSION 1.0
    DESCRIPTION "Some games libs"
    LANGUAGES CXX
)

include(ExternalProject)
ExternalProject_Add(
    Nibleur
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Nibleur"
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND ""
)
ExternalProject_Add(
    Snake
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Snake"
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND ""
)
