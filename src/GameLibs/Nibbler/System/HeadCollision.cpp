/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#include "HeadCollision.hpp"
#include "NibblerCompType.hpp"
#include "MagicValue.hpp"

bool Nibbler::System::HeadCollision::checkCollision(Arcade::ECS::IComponent &fst, std::shared_ptr<Arcade::Graph::Sprite> &head)
{
    Arcade::Graph::Sprite &fstS = static_cast<Arcade::Graph::Sprite&>(fst);

    if (
        (head->pos.x + 5 >= fstS.pos.x + fstS.rect.width - 5) ||
        (head->pos.x + head->rect.width - 5 < fstS.pos.x + 5) ||
        (head->pos.y + 5 > fstS.pos.y + fstS.rect.height - 5) ||
        (head->pos.y + head->rect.height - 5 < fstS.pos.y + 5)
    ) {
        return false;
    }
    return true;
}

void Nibbler::System::HeadCollision::checkHeadBodyCollision(Arcade::ECS::IEntityManager &currentScene, std::shared_ptr<Arcade::Graph::Sprite> headS, Arcade::ECS::IEventManager &eventManager)
{
    std::vector<std::shared_ptr<Arcade::ECS::IEntity>> bodies =
        *(currentScene.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD).get());

    if (bodies.size() < 3) {
        return;
    }
    for (auto const &body : bodies) {
        if (body->getId() == SNAKE_HEAD ||
                body->getId() == std::string(SNAKE_BODY_PART) + "0" ||
                body->getId() == std::string(SNAKE_BODY_PART) + "1" ||
                body->getId() == std::string(SNAKE_BODY_PART) + "2" ||
                body->getId() == std::string(SNAKE_BODY_PART) + "3") {
            continue;
        }
        for (auto const &bodySprite : body->getComponents(Arcade::ECS::CompType::SPRITE)) {
            if (checkCollision(*bodySprite, headS)) {
                eventManager.addEvent(RESTART_EVENT);
                return;
            }
        }
    }
}

void Nibbler::System::HeadCollision::run(double deltaTime, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    std::shared_ptr<Arcade::ECS::IEntity> head = currentScene.getEntitiesById(SNAKE_HEAD);
    std::shared_ptr<Arcade::Graph::Sprite> headS = static_pointer_cast<Arcade::Graph::Sprite>(head->getComponents(Arcade::ECS::CompType::SPRITE).front());
    Arcade::ECS::IComponent &apple = currentScene.getEntitiesById(APPLE_ENTITY)->getComponents(APPLE_SPRITE_COMP);

    checkHeadBodyCollision(currentScene, headS, eventManager);
    if (checkCollision(apple, headS)) {
        eventManager.addEvent(EATED_EVENT);
        return;
    }
    if (headS->pos.x < NIBBLER_PADDING_WINDOW_X ||
            headS->pos.x + headS->rect.width > MAP_RIGHT ||
            headS->pos.y < NIBBLER_PADDING_WINDOW_Y ||
            headS->pos.y + headS->rect.height > MAP_BOTTOM) {
        eventManager.addEvent(RESTART_EVENT);
    }
}
