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
#include "Sprite.hpp"
#include "MoveInput.hpp"

/*
  pos         x             x+CASE_SIZE_WIDTH
   ----------------------------------------------------
   |          |             |            |            |
   |          |             |            |            |
 y |----------bbbbbbbbbbbbbbb------------|------------| y
   |          baaaaaaaaaaaaab            |            | y+(CASE_SIZE_HEIGHT/4)
   |          baaaaaaaaaaaaab            |            | y+CASE_SIZE_HEIGHT-(CASE_SIZE_HEIGHT/4)
   |----------bbbbbbbbbbbbbbb------------|------------| y+CASE_SIZE_HEIGHT
   |          |             |            |            |
   |          |             |            |            |
   |----------|-------------|------------|------------|
   |          |             |            |            |
   |          |             |            |            |
   ----------------------------------------------------
               x+(CASE_SIZE_WIDTH/4)
                           x+CASE_SIZE_WIDTH-(CASE_SIZE_WIDTH/4)
*/

bool Snake::System::MoveDirection::checkHitChangeDir(std::shared_ptr<Snake::Component::ChangeDir> changeDir, std::shared_ptr<Arcade::ECS::IEntity> entity)
{
    auto bodySpriteComps = entity->getComponents(Arcade::ECS::CompType::SPRITE);
    bool hit = false;

    for (auto &bodySpriteComp : bodySpriteComps) {
        auto bodySprite = std::static_pointer_cast<Arcade::Graph::Sprite>(bodySpriteComp);
        if (bodySprite->pos.x + (CASE_SIZE_WIDTH / 4) < changeDir->pos.x ||
            bodySprite->pos.x + CASE_SIZE_WIDTH - (CASE_SIZE_WIDTH / 4) > changeDir->pos.x + CASE_SIZE_WIDTH ||
            bodySprite->pos.y + (CASE_SIZE_HEIGHT / 4) < changeDir->pos.y ||
            bodySprite->pos.y + CASE_SIZE_HEIGHT - (CASE_SIZE_HEIGHT / 4) > changeDir->pos.y + CASE_SIZE_HEIGHT
        ) {
            continue;
        }
        auto &bodyDir = static_cast<Snake::Component::Forward &>(entity->getComponents(FORWARD_KEY));
        auto nextCase = Snake::System::MoveInput::toNextCase(bodySprite->pos, bodyDir.direction);
        bodySprite->pos.x = nextCase.x;
        bodySprite->pos.y = nextCase.y;
        bodyDir.direction = changeDir->direction;
        hit = true;
        break;
    }
    return hit;
}

void Snake::System::MoveDirection::run(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    auto snake = entityManager.getEntitiesById(SNAKE);
    auto directionsComponents = snake->getComponents(Arcade::ECS::CompType::CHANGEDIR);
    auto bodies = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);
    

    for (auto it = directionsComponents.begin(); it != directionsComponents.end();) {
        auto direction = std::static_pointer_cast<Snake::Component::ChangeDir>(*it);
        bool hit = false;
        for (auto bodiesEnt : *bodies) {
            hit = hit | checkHitChangeDir(direction, bodiesEnt);
        }
        if (hit) {
            it++;
        } else {
            it = directionsComponents.erase(it);
        }
    }
}
