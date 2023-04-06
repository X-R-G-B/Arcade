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
#include "MoveInput.hpp"
#include "SnakeCompType.hpp"

void Snake::System::MoveForward::moveForward(
    Snake::Component::Forward &curDir,
    Arcade::Graph::ISprite &sprite,
    double vector)
{
    auto dirNext = Snake::System::MoveInput::toNextCase(sprite.pos, curDir.direction);

    if (curDir.direction == Direction::UP) {
        sprite.pos.y -= vector;
        sprite.pos.x = dirNext.x;
    } else if (curDir.direction == Direction::DOWN) {
        sprite.pos.y += vector;
        sprite.pos.x = dirNext.x;
    } else if (curDir.direction == Direction::LEFT) {
        sprite.pos.x -= vector;
        sprite.pos.y = dirNext.y;
    } else if (curDir.direction == Direction::RIGHT) {
        sprite.pos.x += vector;
        sprite.pos.y = dirNext.y;
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
