cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade_nibbler PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(arcade_nibbler PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/NibblerMapComponent.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/NibblerWallComponent.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Forward.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SnakeGrow.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ChangeDir.cpp"
)
