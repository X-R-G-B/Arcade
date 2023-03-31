/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#include "ISprite.hpp"
#include "Direction.hpp"
#include "Forward.hpp"
#include "MoveForward.hpp"
#include "MagicValue.hpp"
#include "ChangeDir.hpp"

Snake::System::MoveForward::MoveForward()
{
}

void Snake::System::MoveForward::run(
    float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto head = currentEntityManager.getEntitiesById(SNAKE_HEAD);
    auto &curDir = static_cast<Component::Forward &>(head->getComponents(SNAKE_HEAD_DIR_COMP));
    auto &sprite = static_cast<Arcade::Graph::ISprite &>(head->getComponents(SNAKE_HEAD_SPRITE_COMP));

    switch (curDir.direction) {
        case Snake::Direction::UP:
            sprite.pos.y -= deltaTime * SNAKE_MOVE_PER_DTIME;
        case Snake::Direction::DOWN:
            sprite.pos.y += deltaTime * SNAKE_MOVE_PER_DTIME;
        case Snake::Direction::LEFT:
            sprite.pos.x -= deltaTime * SNAKE_MOVE_PER_DTIME;
        case Snake::Direction::RIGHT:
            sprite.pos.x += deltaTime * SNAKE_MOVE_PER_DTIME;
    };
}
