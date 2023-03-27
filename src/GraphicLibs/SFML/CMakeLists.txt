cmake_minimum_required(VERSION 3.3)

project(arcade_sfml)

find_package(SFML REQUIRED COMPONENTS graphics)

target_sources(arcade_sfml PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Sfml.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Text.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp"
    )
    
target_link_libraries(arcade_sfml PRIVATE sfml-graphics)
