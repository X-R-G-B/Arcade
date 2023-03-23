##
## EPITECH PROJECT, 2023
## Arcade
## File description:
## test_EntityManagerMain
##

set -x
set -e

g++ tests/Arcade/ECS/EntityManagerMain.cpp src/Arcade/ECS/EntityManager.cpp src/Arcade/ECS/Entity.cpp -Isrc/Arcade/ECS -Isrc/Arcade -std=c++20 -o tests/Arcade/ECS/EntityManagerMain.out
./tests/Arcade/ECS/EntityManagerMain.out
