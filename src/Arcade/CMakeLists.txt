cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

file(GLOB SOURCES LibHandler.cpp)

add_subdirectory(Core)
add_subdirectory(ECS)
add_subdirectory(Game)
add_subdirectory(Graph)
