set -x
set -e

g++ src/Arcade/Game/SceneManager.cpp tests/Arcade/Game/SceneTest.cpp -Isrc/Arcade/ECS -Isrc/Arcade -Isrc/Arcade/Game -std=c++20 -o test_SManager
./test_SManager