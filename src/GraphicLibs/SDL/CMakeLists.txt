cmake_minimum_required(VERSION 3.13)

target_sources(arcade_sdl2 PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/EventHandler.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SDL.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Sprite.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Text.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Music.cpp"
)

find_library(LSDLGRAPHICS SDL2 SDL2_image SDL2_ttf SDL2_mixer)
target_link_libraries(arcade_sdl2 PRIVATE ${LSDLGRAPHICS})
