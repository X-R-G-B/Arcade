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
#include "NibblerCompType.hpp"
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

static const double PADDING_SIZE = PARCELL_SIZE / 12.0;

bool Nibbler::System::MoveDirection::checkHitChangeDir(
    std::shared_ptr<Nibbler::Component::ChangeDir> changeDir,
    std::shared_ptr<Arcade::ECS::IEntity> entity,
    Arcade::ECS::IComponent &bodyGrow)
{
    auto &bodySpriteComps = entity->getComponents(Arcade::ECS::CompType::SPRITE);
    auto &bodyGrowComp = static_cast<Nibbler::Component::SnakeGrow &>(bodyGrow);
    bool hit = false;

    for (auto &bodySpriteComp : bodySpriteComps) {
        auto bodySprite = std::static_pointer_cast<Arcade::Graph::Sprite>(bodySpriteComp);
        if (bodySprite->pos.x + PADDING_SIZE < changeDir->pos.x ||
            bodySprite->pos.x + PARCELL_SIZE - (PADDING_SIZE) > changeDir->pos.x + PARCELL_SIZE ||
            bodySprite->pos.y + PADDING_SIZE < changeDir->pos.y ||
            bodySprite->pos.y + PARCELL_SIZE - PADDING_SIZE > changeDir->pos.y + PARCELL_SIZE
        ) {
            continue;
        }
        auto &bodyDir = static_cast<Nibbler::Component::Forward &>(entity->getComponents(FORWARD_KEY));
        // auto nextCase = Nibbler::System::MoveInput::toNextCase(bodySprite->pos, bodyDir.direction);
        // bodySprite->pos.x = nextCase.x;
        // bodySprite->pos.y = nextCase.y;
        bodyDir.direction = changeDir->direction;
        if (entity->getId() == bodyGrowComp.lastIdBodyComp) {
            hit = true;
            break;
        }
    }
    return hit;
}

void Nibbler::System::MoveDirection::run(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    auto snake = entityManager.getEntitiesById(NIBBLER_HEAD);
    auto bodies = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);
    auto &lastSnakeBody = entityManager.getEntitiesById(NIBBLER)->getComponents(NIBBLER_GROW_COMPONENT);
    auto directionsComponents = snake->getComponents(Arcade::ECS::CompType::CHANGEDIR);

    for (auto &dirIt : directionsComponents) {
        auto direction = std::static_pointer_cast<Nibbler::Component::ChangeDir>(dirIt);
        for (auto &bodiesEnt : *bodies) {
            bool last = checkHitChangeDir(direction, bodiesEnt, lastSnakeBody);
            if (last) {
                snake->removeComponent(direction->id);
                continue;
            }
        }
    }
}
