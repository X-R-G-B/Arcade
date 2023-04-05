/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#include "HeadCollision.hpp"
#include "SnakeCompType.hpp"
#include "MagicValue.hpp"

#include <iostream>
bool Snake::System::HeadCollision::checkCollision(Arcade::ECS::IComponent &fst, std::shared_ptr<Arcade::Graph::Sprite> &head)
{
    Arcade::Graph::Sprite &fstS = static_cast<Arcade::Graph::Sprite&>(fst);

    if((head->pos.x >= fstS.pos.x + fstS.rect.width)
        || (head->pos.x + head->rect.width <= fstS.pos.x)
        || (head->pos.y >= fstS.pos.y + fstS.rect.height)
        || (head->pos.y + head->rect.height <= fstS.pos.y)) {
        return false;
    }
    return true;
}

void Snake::System::HeadCollision::checkHeadBodyCollision(Arcade::ECS::IEntityManager &currentScene, std::shared_ptr<Arcade::Graph::Sprite> headS, Arcade::ECS::IEventManager &eventManager)
{
    std::vector<std::shared_ptr<Arcade::ECS::IEntity>> bodies =
        *(currentScene.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD).get());

    if (bodies.size() < 2) {
        return;
    }
    for (auto const &body : bodies) {
        if (body->getId() == SNAKE_HEAD) {
            continue;
        }
        for (auto const &bodySprite : body->getComponents(Arcade::ECS::CompType::SPRITE)) {
            if (checkCollision(*(bodySprite.get()), headS)) {
                eventManager.addEvent(RESTART_EVENT);
                return;
            }
        }
    }
}

void Snake::System::HeadCollision::run(double deltaTime, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    std::shared_ptr<Arcade::ECS::IEntity> head = currentScene.getEntitiesById(SNAKE_HEAD);
    std::shared_ptr<Arcade::Graph::Sprite> headS = static_pointer_cast<Arcade::Graph::Sprite>(head->getComponents(Arcade::ECS::CompType::SPRITE).front());
    Arcade::ECS::IComponent &apple = currentScene.getEntitiesById(APPLE_ENTITY)->getComponents(APPLE_SPRITE_COMP);

    checkHeadBodyCollision(currentScene, headS, eventManager);
    if (checkCollision(apple, headS)) {
        eventManager.addEvent(EATED_EVENT);
        std::cout << "event added" << std::endl;
        if (eventManager.isEventTriggered(EATED_EVENT).first) {
            std::cout << "event triggered" << std::endl;
        }
        return;
    }
    if (headS->pos.x <= 0 || headS->pos.x + headS->rect.width >= 1920 || headS->pos.y <= 0 || headS->pos.y + headS->rect.height >= 1080) {
        eventManager.addEvent(RESTART_EVENT);
    }
}
