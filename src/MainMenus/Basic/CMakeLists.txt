cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade_menu_main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(arcade_menu_main PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/MainMenuModule.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/MainMenuScene.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/EntryPoint.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/MainMenuSystem.cpp"
)
