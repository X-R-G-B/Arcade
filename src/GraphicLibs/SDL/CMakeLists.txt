cmake_minimum_required(VERSION 3.13)

target_sources(arcade_sdl2 PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/EventHandler.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SDL.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Sprite.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Text.cpp"
)

find_library(LSDL2 SDL2)
find_library(LSDL2_image SDL2_image)
find_library(LSDL2_text SDL2_ttf)
find_library(LSDL2_music SDL2_mixer)
target_link_libraries(arcade_sdl2 PRIVATE ${LSDL2} ${LSDL2_image} ${LSDL2_text} ${LSDL2_music})
