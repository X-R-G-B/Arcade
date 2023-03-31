cmake_minimum_required(VERSION 3.3)

target_include_directories(arcade_snake PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(arcade_snake PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Move.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/AppleSystem.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/EatSystem.cpp"
)
