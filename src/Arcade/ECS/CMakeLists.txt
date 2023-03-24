cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(arcade PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/EventManager.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/AComponent.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entity.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/EntityManager.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ComponentManager.cpp"
)
