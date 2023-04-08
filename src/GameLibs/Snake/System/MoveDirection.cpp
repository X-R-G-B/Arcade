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

static const double PADDING_SIZE = PARCELL_SIZE / 12.0;

bool Snake::System::MoveDirection::checkHitChangeDir(
    std::shared_ptr<Snake::Component::ChangeDir> changeDir,
    std::shared_ptr<Arcade::ECS::IEntity> entity,
    Arcade::ECS::IComponent &bodyGrow)
{
    std::puts("checkHitChangeDir");
    auto &bodySpriteComps = entity->getComponents(Arcade::ECS::CompType::SPRITE);
    std::puts("bodyGrowComp");
    auto &bodyGrowComp = static_cast<Snake::Component::SnakeGrow &>(bodyGrow);
    std::puts("hit");
    bool hit = false;

    std::puts("for");
    for (auto &bodySpriteComp : bodySpriteComps) {
        std::puts("bodySprite");
        auto bodySprite = std::static_pointer_cast<Arcade::Graph::Sprite>(bodySpriteComp);
        std::printf("bodySprite->pos.x: %p\n", bodySprite->pos.x);
        std::puts("if");
//        if (bodySprite->pos.x + PADDING_SIZE < changeDir->pos.x ||
//            bodySprite->pos.x + PARCELL_SIZE - (PADDING_SIZE) > changeDir->pos.x + PARCELL_SIZE ||
//            bodySprite->pos.y + PADDING_SIZE < changeDir->pos.y ||
//            bodySprite->pos.y + PARCELL_SIZE - (PADDING_SIZE) > changeDir->pos.y + PARCELL_SIZE
//        ) {
        std::puts("continue1");
        if (bodySprite->pos.x) {
            std::puts("continue1.1");
        }
        std::puts("continue1.2");
        if (bodySprite->pos.x + PADDING_SIZE) {
            std::puts("continue1.2");
        }
        std::puts("continue1.3");
        if (changeDir->pos.x) {
            std::puts("continue1.3");
        }
        std::puts("continue1.4");
        if (bodySprite->pos.x + PADDING_SIZE < changeDir->pos.x) {
            continue;
        }
        std::puts("continue2");
        if (bodySprite->pos.x + PARCELL_SIZE - (PADDING_SIZE) > changeDir->pos.x + PARCELL_SIZE) {
            continue;
        }
        std::puts("continue3");
        if (bodySprite->pos.y + PADDING_SIZE < changeDir->pos.y) {
            continue;
        }
        std::puts("continue4");
        if (bodySprite->pos.y + PARCELL_SIZE - (PADDING_SIZE) > changeDir->pos.y + PARCELL_SIZE) {
            continue;
        }

        std::puts("bodyDir");
        auto &bodyDir = static_cast<Snake::Component::Forward &>(entity->getComponents(FORWARD_KEY));
        // auto nextCase = Snake::System::MoveInput::toNextCase(bodySprite->pos, bodyDir.direction);
        // bodySprite->pos.x = nextCase.x;
        // bodySprite->pos.y = nextCase.y;
        std::puts("bodyDir.direction = changeDir->direction;");
        bodyDir.direction = changeDir->direction;
        std::puts("if");
        if (entity->getId() == bodyGrowComp.lastIdBodyComp) {
            std::puts("hit = true;");
            hit = true;
            break;
        }
        std::puts("break");
    }
    std::puts("return");
    return hit;
}

void Snake::System::MoveDirection::run(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    auto snake = entityManager.getEntitiesById(SNAKE_HEAD);
    auto bodies = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);
    auto &lastSnakeBody = entityManager.getEntitiesById(SNAKE)->getComponents(SNAKE_GROW_COMPONENT);
    auto &directionsComponents = snake->getComponents(Arcade::ECS::CompType::CHANGEDIR);

    for (auto &dirIt : directionsComponents) {
        auto direction = std::static_pointer_cast<Snake::Component::ChangeDir>(dirIt);
        for (auto &bodiesEnt : *bodies) {
            bool last = checkHitChangeDir(direction, bodiesEnt, lastSnakeBody);
            if (last) {
                snake->removeComponent(direction->id);
                continue;
            }
        }
    }
}
