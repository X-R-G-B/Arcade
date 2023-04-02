/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** SnakeMapEntity
*/

#include "SnakeMapEntity.hpp"
#include "SnakeMapComponent.hpp"

Snake::Entity::SnakeMapEntity::SnakeMapEntity()
    : Arcade::ECS::Entity(SNAKE_MAP_ID)
{
    static const int nbrOfParcelsInLine = 6;
    static const int paddingX = 576;
    static const int paddingY = 156;
    int snakeMapParcelNbr = 0;

    for (int y = 0; y < nbrOfParcelsInLine; y++, snakeMapParcelNbr++) {
        for (int x = 0; x < nbrOfParcelsInLine; x++, snakeMapParcelNbr++) {
            this->addComponent(
            std::make_shared<Snake::Component::SnakeMapComponent>(
            SNAKE_MAP_ID + "_" + std::to_string(snakeMapParcelNbr),
            Arcade::Vector3f(
            paddingX + x * SNAKE_MAP_SIZE, paddingY + y * SNAKE_MAP_SIZE, 0)));
        }
    }
}