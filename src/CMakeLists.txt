cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(arcade PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/libHandler.cpp"
)
add_subdirectory(Arcade)