/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#include "HeadCollision.hpp"
#include "Snake.hpp"
#include "Sprite.hpp"

bool checkCollision(Arcade::ECS::IComponent &fst, Arcade::Graph::Sprite &head)
{
    Arcade::Graph::Sprite &fstS = static_cast<Arcade::Graph::Sprite&>(fst);

    if((head.pos.x >= fstS.pos.x + fstS.rect.width)
        || (head.pos.x + head.rect.width <= fstS.pos.x)
        || (head.pos.y >= fstS.pos.y + fstS.rect.height)
        || (head.pos.y + head.rect.height <= fstS.pos.y)) {
        return false;
    } else {
        return true;
    }
}

void Snake::System::HeadCollision::run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    std::shared_ptr<Arcade::ECS::IEntity> head = currentScene.getEntitiesById("head");
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>> bodies = currentScene.getEntitiesByComponentType(Arcade::ECS::CompType::DIRECTION);
    Arcade::ECS::IComponent &apple = currentScene.getEntitiesById("apple")->getComponents("sprite");
    Arcade::Graph::Sprite &headS = static_cast<Arcade::Graph::Sprite&>(*(head->getComponents(Arcade::ECS::CompType::SPRITE).front().get()));

    for (auto const &body : *(bodies.get())) {
        if (body->getId() == "head") {
            continue;
        }
        for (auto const &bodySprite : body->getComponents(Arcade::ECS::CompType::SPRITE)) {
            if (checkCollision(*(bodySprite.get()), headS)) {
                eventManager.addEvent("RESTART");
                return;
            }
        }
    }
    if (checkCollision(apple, headS)) {
        eventManager.addEvent("EATED");
        return;
    }
    if (headS.pos.x <= 0 || headS.pos.x + headS.rect.width >= 1920 || headS.pos.y <= 0 || headS.pos.y + headS.rect.height >= 1080) {
        eventManager.addEvent("RESTART");
    }
}
