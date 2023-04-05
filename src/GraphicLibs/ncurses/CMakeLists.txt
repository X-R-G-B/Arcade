cmake_minimum_required(VERSION 3.13)

target_sources(arcade_ncurses PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Ncurses.cpp"
)

include(FetchContent)
# Example took from https://cmake.org/cmake/help/latest/module/FetchContent.html
FetchContent_Declare(miniaudio
    GIT_REPOSITORY https://github.com/mackron/miniaudio.git
    GIT_TAG        9a7663496fc06f7a9439c752fd7666ca93328c20
)
FetchContent_MakeAvailable(miniaudio)
target_include_directories(arcade_ncurses PRIVATE ${miniaudio_SOURCE_DIR})
