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

void Snake::System::MoveForward::moveForward(
    Snake::Component::Forward &curDir,
    Arcade::Graph::ISprite &sprite,
    double vector)
{
    int caseCurX = (TO_INT(sprite.pos.x)) % PARCELL_SIZE;
    int caseCurY = (TO_INT(sprite.pos.y)) % PARCELL_SIZE;

    if (curDir.direction == Direction::UP) {
        sprite.pos.y -= vector;
        sprite.pos.x = caseCurX;
    } else if (curDir.direction == Direction::DOWN) {
        sprite.pos.y += vector;
        sprite.pos.x = caseCurX;
    } else if (curDir.direction == Direction::LEFT) {
        sprite.pos.x -= vector;
        sprite.pos.y = caseCurY;
    } else if (curDir.direction == Direction::RIGHT) {
        sprite.pos.x += vector;
        sprite.pos.y = caseCurY;
    }
}

void Snake::System::MoveForward::run(
    double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto snakes = currentEntityManager.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);
    double move = SNAKE_MOVE_PER_DTIME * deltaTime;

    for (auto &it : *snakes) {
        auto curDir = static_cast<Component::Forward &>(it->getComponents(FORWARD_KEY));
        auto &sprite = static_cast<Arcade::Graph::ISprite &>(it->getComponents(SNAKE_SPRITE));
        moveForward(curDir, sprite, move);
    }
}
