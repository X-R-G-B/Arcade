cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(arcade PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LibHandler.cpp"
)

find_library(LDL dl)
target_link_libraries(arcade PRIVATE ${LDL})

add_subdirectory(Core)
add_subdirectory(ECS)
add_subdirectory(Game)
add_subdirectory(Graph)
