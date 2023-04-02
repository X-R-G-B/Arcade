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

void Snake::System::MoveDirection::checkHitChangeDir(std::shared_ptr<Snake::Component::ChangeDir> changeDir, std::shared_ptr<Arcade::ECS::IEntity> entity)
{
    auto bodySpriteComps = entity->getComponents(Arcade::ECS::CompType::SPRITE);

    for (auto &bodySpriteComp : bodySpriteComps) {
        auto bodySprite = std::static_pointer_cast<Arcade::Graph::Sprite>(bodySpriteComp);
        if (bodySprite->pos.x > changeDir->pos.x + (CASE_SIZE_WIDTH / 3) ||
                bodySprite->pos.x < changeDir->pos.x - (CASE_SIZE_WIDTH / 3)) {
            continue;
        }
        if (bodySprite->pos.y > changeDir->pos.y + (CASE_SIZE_HEIGHT / 3) ||
                bodySprite->pos.y < changeDir->pos.y - (CASE_SIZE_HEIGHT / 3)) {
            continue;
        }
        auto &bodyDir = static_cast<Snake::Component::Forward &>(entity->getComponents(MOVEABLE_KEY));
        auto nextCase = Snake::System::MoveInput::toNextCase(bodySprite->pos, bodyDir.direction);
        bodySprite->pos.x = nextCase.x;
        bodySprite->pos.y = nextCase.y;
        bodyDir.direction = changeDir->direction;
    }
}

void Snake::System::MoveDirection::run(float deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    auto directionsEntities = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::CHANGEDIR);
    auto bodies = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);

    for (auto &directionEntity : *directionsEntities) {
        auto directionComponents = directionEntity->getComponents(Arcade::ECS::CompType::CHANGEDIR);
        for (auto &directionComponent : directionComponents) {
            auto direction = std::static_pointer_cast<Snake::Component::ChangeDir>(directionComponent);
            for (auto bodiesEnt : *bodies) {
                checkHitChangeDir(direction, bodiesEnt);
            }
        }
    }
}
