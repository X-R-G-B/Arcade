/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MoveDirection
*/

#include <iterator>
#include <memory>
#include <vector>
#include "Forward.hpp"
#include "MoveDirection.hpp"
#include "MagicValue.hpp"
#include "SnakeCompType.hpp"
#include "ChangeDir.hpp"
#include "Sprite.hpp"
#include "MoveInput.hpp"

static void checkHitChangeDir(std::shared_ptr<Snake::Component::ChangeDir> changeDir, std::shared_ptr<Arcade::ECS::IEntity> entity)
{
    auto bodySpriteComps = entity->getComponents(Arcade::ECS::CompType::SPRITE);

    for (auto &bodySpriteComp : bodySpriteComps) {
        auto bodySprite = std::static_pointer_cast<Arcade::Graph::Sprite>(bodySpriteComp);
        if (bodySprite->pos.x > changeDir->pos.x + (CASE_SIZE_WIDTH / 2) ||
                bodySprite->pos.x < changeDir->pos.x - (CASE_SIZE_WIDTH / 2)) {
            continue;
        }
        if (bodySprite->pos.y > changeDir->pos.y + (CASE_SIZE_HEIGHT / 2) ||
                bodySprite->pos.y < changeDir->pos.y - (CASE_SIZE_HEIGHT / 2)) {
            continue;
        }
        auto &bodyDir = static_cast<Snake::Component::Forward &>(entity->getComponents(MOVEABLE_KEY));
        auto nextCase = Snake::System::toNextCase(bodySprite->pos, bodyDir.direction);
        bodySprite->pos.x = nextCase.x;
        bodySprite->pos.y = nextCase.y;
        bodyDir.direction = changeDir->direction;
    }
}

void Snake::System::MoveDirection::run(float deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    auto snake = entityManager.getEntitiesById(SNAKE_HEAD);
    auto directions = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::MOVEABLE);
    auto bodies = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::BODYCOMP);

    for (auto &directionEnt : *directions) {
        auto directionComponents = directionEnt->getComponents(Arcade::ECS::CompType::MOVEABLE);
        for (auto &directionComp : directionComponents) {
            auto direction = std::static_pointer_cast<Snake::Component::ChangeDir>(directionComp);
            checkHitChangeDir(direction, snake);
            for (auto bodiesEnt : *bodies) {
                checkHitChangeDir(direction, bodiesEnt);
            }
        }
    }
}
