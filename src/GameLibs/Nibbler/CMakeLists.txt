cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade_nibbler PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(arcade_nibbler PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Nibbler.cpp"
)

add_subdirectory(Component)
add_subdirectory(System)
add_subdirectory(Scene)
