/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#include <memory>
#include "IEntity.hpp"
#include "ISprite.hpp"
#include "Direction.hpp"
#include "Forward.hpp"
#include "MoveForward.hpp"
#include "MagicValue.hpp"
#include "SnakeCompType.hpp"

#include <iostream>
void Snake::System::MoveForward::moveForward(
    Snake::Component::Forward &curDir,
    Arcade::Graph::ISprite &sprite,
    double deltaTime)
{
    if (curDir.direction == Direction::UP) {
        sprite.pos.y -= deltaTime * SNAKE_MOVE_PER_DTIME;
    } else if (curDir.direction == Direction::DOWN) {
        sprite.pos.y += deltaTime * SNAKE_MOVE_PER_DTIME;
    } else if (curDir.direction == Direction::LEFT) {
        sprite.pos.x -= deltaTime * SNAKE_MOVE_PER_DTIME;
    } else if (curDir.direction == Direction::RIGHT) {
        sprite.pos.x += deltaTime * SNAKE_MOVE_PER_DTIME;
    }
}

void Snake::System::MoveForward::run(
    double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    return;
    auto snakes = currentEntityManager.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);

    for (auto &it : *snakes) {
        auto curDir = static_cast<Component::Forward &>(it->getComponents(FORWARD_KEY));
        auto &sprite = static_cast<Arcade::Graph::ISprite &>(it->getComponents(SNAKE_SPRITE));
        moveForward(curDir, sprite, deltaTime);
    }
}
