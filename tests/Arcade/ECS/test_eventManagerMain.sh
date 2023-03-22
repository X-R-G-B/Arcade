set -x
set -e

g++ tests/Arcade/ECS/EventManagerMain.cpp src/Arcade/ECS/EventManager.cpp -Isrc/Arcade/ECS -Isrc/Arcade -std=c++20 -o tests/Arcade/ECS/EventManagerMain.out
./tests/Arcade/ECS/EventManagerMain.out
