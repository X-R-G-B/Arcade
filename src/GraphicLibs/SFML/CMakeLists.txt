cmake_minimum_required(VERSION 3.13)

target_sources(arcade_sfml PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Sfml.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Music.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Text.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Sprite.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SFML_EventHandler.cpp"
)

find_library(LSFMLGRAPHICS sfml-graphics)
find_library(LSFMLWINDOW sfml-window)
find_library(LSFMLSYSTEM sfml-system)
find_library(LSFMLAUDIO sfml-audio)
target_link_libraries(arcade_sfml PRIVATE ${LSFMLGRAPHICS} ${LSFMLWINDOW} ${LSFMLSYSTEM} ${LSFMLAUDIO})
