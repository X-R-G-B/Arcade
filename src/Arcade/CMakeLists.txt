cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(arcade_menu_main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(arcade_nibbler PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(arcade_snake PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(arcade_ncurses PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(arcade_sdl2 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(arcade_sfml PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(arcade PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
)

find_library(LDL dl)
target_link_libraries(arcade PRIVATE ${LDL})

add_subdirectory(Core)
add_subdirectory(ECS)
add_subdirectory(Game)
add_subdirectory(Graph)
add_subdirectory(MainMenu)
