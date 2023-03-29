cmake_minimum_required(VERSION 3.13)

target_sources(arcade_sfml PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Sfml.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Music.cpp"
)

find_library(LSFMLGRAPHICS sfml-graphics)
target_link_libraries(arcade_sfml PRIVATE ${LSFMLGRAPHICS})
