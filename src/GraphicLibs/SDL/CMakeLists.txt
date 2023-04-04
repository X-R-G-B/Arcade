cmake_minimum_required(VERSION 3.13)

target_sources(arcade_sdl2 PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/EventHandler.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SDL.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Sprite.cpp"
)
