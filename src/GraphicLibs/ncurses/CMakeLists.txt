cmake_minimum_required(VERSION 3.13)

target_sources(arcade_ncurses PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Ncurses.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/TEXT.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SPRITE.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/MUSIC.cpp"
)

find_library(LNCURSES_GRAPHICS ncurses)
target_link_libraries(arcade_ncurses PRIVATE ${LNCURSES_GRAPHICS})
