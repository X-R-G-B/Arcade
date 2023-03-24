cmake_minimum_required(VERSION 3.13)

target_include_directories(arcade PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(arcade PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Core.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Module.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameModule.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/DisplayModule.cpp"
)
