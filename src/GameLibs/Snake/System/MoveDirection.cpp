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
#include "IComponent.hpp"
#include "MoveDirection.hpp"
#include "MagicValue.hpp"
#include "SnakeCompType.hpp"
#include "SnakeGrow.hpp"
#include "Sprite.hpp"
#include "MoveInput.hpp"
#include "Exceptions.hpp"

/*
  pos         x             x+PARCELL_SIZE
   ----------------------------------------------------
   |          |             |            |            |
   |          |             |            |            |
 y |----------bbbbbbbbbbbbbbb------------|------------| y
   |          baaaaaaaaaaaaab            |            | y+(PARCELL_SIZE/4)
   |          baaaaaaaaaaaaab            |            | y+PARCELL_SIZE-(PARCELL_SIZE/4)
   |----------bbbbbbbbbbbbbbb------------|------------| y+PARCELL_SIZE
   |          |             |            |            |
   |          |             |            |            |
   |----------|-------------|------------|------------|
   |          |             |            |            |
   |          |             |            |            |
   ----------------------------------------------------
               x+(PARCELL_SIZE/4)
                           x+PARCELL_SIZE-(PARCELL_SIZE/4)
*/

bool Snake::System::MoveDirection::checkHitChangeDir(
    std::shared_ptr<Snake::Component::ChangeDir> changeDir,
    std::shared_ptr<Arcade::ECS::IEntity> entity,
    Arcade::ECS::IComponent &bodyGrow)
{
    auto &bodySpriteComps = entity->getComponents(Arcade::ECS::CompType::SPRITE);
    auto &bodyGrowComp = static_cast<Snake::Component::SnakeGrow &>(bodyGrow);
    bool hit = false;

    for (auto &bodySpriteComp : bodySpriteComps) {
        auto bodySprite = std::static_pointer_cast<Arcade::Graph::Sprite>(bodySpriteComp);
        if (bodySprite->pos.x + (PARCELL_SIZE / 4) < changeDir->pos.x ||
            bodySprite->pos.x + PARCELL_SIZE - (PARCELL_SIZE / 4) > changeDir->pos.x + PARCELL_SIZE ||
            bodySprite->pos.y + (PARCELL_SIZE / 4) < changeDir->pos.y ||
            bodySprite->pos.y + PARCELL_SIZE - (PARCELL_SIZE / 4) > changeDir->pos.y + PARCELL_SIZE
        ) {
            continue;
        }
        auto &bodyDir = static_cast<Snake::Component::Forward &>(entity->getComponents(FORWARD_KEY));
        auto nextCase = Snake::System::MoveInput::toNextCase(bodySprite->pos, bodyDir.direction);
        bodySprite->pos.x = nextCase.x;
        bodySprite->pos.y = nextCase.y;
        bodyDir.direction = changeDir->direction;
        if (entity->getId() == bodyGrowComp.lastIdBodyComp) {
            hit = true;
            break;
        }
    }
    return hit;
}

void Snake::System::MoveDirection::run(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    auto snake = entityManager.getEntitiesById(SNAKE_HEAD);
    std::vector<std::shared_ptr<Arcade::ECS::IComponent>> directionsComponents;
    auto bodies = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);
    auto &lastSnakeBody = entityManager.getEntitiesById(SNAKE)->getComponents(SNAKE_GROW_COMPONENT);

    try {
        directionsComponents = snake->getComponents(Arcade::ECS::CompType::CHANGEDIR);
    } catch (ArcadeExceptions &e) {
        return;
    }

    for (auto &dirIt : directionsComponents) {
        auto direction = std::static_pointer_cast<Snake::Component::ChangeDir>(dirIt);
        for (auto bodiesEnt : *bodies) {
            bool last = checkHitChangeDir(direction, bodiesEnt, lastSnakeBody);
            if (last) {
                snake->removeComponent(direction->id);
                continue;
            }
        }
    }
}
