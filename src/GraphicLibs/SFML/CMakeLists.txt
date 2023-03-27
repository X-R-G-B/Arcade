cmake_minimum_required(VERSION 3.3)

target_sources(arcade_sfml PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Sfml.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Text.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp"
)
