cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade_snake PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(arcade_snake PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ChangeDir.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Forward.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SnakeGrow.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SnakeMapComponent.cpp"
)
