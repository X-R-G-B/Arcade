cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade_snake PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(arcade_snake PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/AppleSystem.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/EatSystem.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/HeadCollision.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/MoveDirection.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/MoveForward.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/MoveInput.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Restart.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SnakeGrowSystem.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/InputsSystem.cpp"
)
