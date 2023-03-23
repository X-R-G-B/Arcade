set -x
set -e

g++ tests/Arcade/ECS/EntityMain.cpp src/Arcade/ECS/Entity.cpp -Isrc/Arcade/ECS -Isrc/Arcade -std=c++20 -o tests/Arcade/ECS/EntityMain.out
./tests/Arcade/ECS/EntityMain.out
