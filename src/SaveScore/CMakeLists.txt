cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade_snake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(arcade_snake PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/SaveScore.cpp"
)

target_include_directories(arcade_menu_main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(arcade_menu_main PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/SaveScore.cpp"
)

target_include_directories(arcade_nibbler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(arcade_nibbler PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/SaveScore.cpp"
)
