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
#include "ChangeDir.hpp"
#include "SnakeCompType.hpp"

void Snake::System::MoveForward::moveForward(
    Snake::Component::Forward &curDir,
    Arcade::Graph::ISprite &sprite,
    float deltaTime)
{
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

void Snake::System::MoveForward::run(
    float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto snakes = currentEntityManager.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);

    for (auto &it : *snakes) {
        auto curDir = static_cast<Component::Forward &>(it->getComponents(FORWARD_KEY));
        auto sprite = static_cast<Arcade::Graph::ISprite &>(it->getComponents(SNAKE_HEAD_SPRITE_COMP));
        moveForward(curDir, sprite, deltaTime);
    }
}
