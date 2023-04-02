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

Snake::System::MoveForward::MoveForward()
{
}

static void moveForward(
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
    auto head = currentEntityManager.getEntitiesById(SNAKE_HEAD);
    auto &curDir = static_cast<Component::Forward &>(head->getComponents(MOVEABLE_KEY));
    auto &sprite = static_cast<Arcade::Graph::ISprite &>(head->getComponents(SNAKE_HEAD_SPRITE_COMP));
    moveForward(curDir, sprite, deltaTime);
    auto tail = currentEntityManager.getEntitiesByComponentType(Arcade::ECS::CompType::BODYCOMP);

    for (auto &it : *tail) {
        curDir = static_cast<Component::Forward &>(it->getComponents(MOVEABLE_KEY));
        sprite = static_cast<Arcade::Graph::ISprite &>(it->getComponents(SNAKE_HEAD_SPRITE_COMP));
        moveForward(curDir, sprite, deltaTime);
    }
}
