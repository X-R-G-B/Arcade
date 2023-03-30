cmake_minimum_required(VERSION 3.13)

target_sources(arcade_snake PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Snake.cpp"
)

add_subdirectory(Scene)
add_subdirectory(System)
