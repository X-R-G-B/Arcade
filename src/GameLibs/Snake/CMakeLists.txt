cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade_snake PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(arcade_snake PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Snake.cpp"
)

add_subdirectory(Component)
add_subdirectory(System)
add_subdirectory(Scene)
