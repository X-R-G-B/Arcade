cmake_minimum_required(VERSION 3.13)

target_sources(arcade_sfml PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/SFML_EventHandler.cpp"
)

find_library(LSFMLGRAPHICS sfml-graphics sfml-window sfml-system)
target_link_libraries(arcade_sfml PRIVATE ${LSFMLGRAPHICS})