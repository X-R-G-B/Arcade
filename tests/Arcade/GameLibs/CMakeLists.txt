cmake_minimum_required(VERSION 3.3)
project(
    Test_Game_Cout
    VERSION 1.0
    DESCRIPTION "test game in cout"
    LANGUAGES CXX
)

add_library(arcade_test_game_cout SHARED)
target_include_directories(arcade_test_game_cout PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/Arcade/ECS"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/Arcade/Game"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/Arcade/Graph"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/Arcade"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src"
)

target_sources(arcade_test_game_cout PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/cout_test.cpp"
)
