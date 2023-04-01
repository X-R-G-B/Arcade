/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#include "HeadCollision.hpp"
#include "Snake.hpp"
#include "SnakeCompType.hpp"
#include "Sprite.hpp"

bool checkCollision(Arcade::ECS::IComponent &fst, std::shared_ptr<Arcade::Graph::Sprite> &head)
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
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>> bodies = currentScene.getEntitiesByComponentType(Arcade::ECS::CompType::MOVEABLE);
    Arcade::ECS::IComponent &apple = currentScene.getEntitiesById("apple")->getComponents("sprite");
    std::shared_ptr<Arcade::Graph::Sprite> headS = static_cast<std::shared_ptr<Arcade::Graph::Sprite>>(head->getComponents(Arcade::ECS::CompType::SPRITE).front());

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
    if (head->pos.x <= 0 || head->pos.x + head->rect.width >= 1920 || head->pos.y <= 0 || head->pos.y + head->rect.height >= 1080) {
        eventManager.addEvent("RESTART");
    }
}
