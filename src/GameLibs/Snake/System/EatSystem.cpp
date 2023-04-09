/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EatSystem
*/

#include "EatSystem.hpp"
#include "SnakeCompType.hpp"
#include "MagicValue.hpp"
#include "SnakeGrow.hpp"
#include "Music.hpp"
#include <string>

static const std::string abc = "abc";

void Snake::System::EatSystem::run(double deltaTime,
                              Arcade::ECS::IEventManager &eventManager,
                              Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto snakeEntity = currentEntityManager.getEntitiesById(SNAKE);
    auto &snakeIncrIComp = snakeEntity->getComponents(SNAKE_GROW_COMPONENT);

    if (snakeIncrIComp.type == Arcade::ECS::CompType::SNAKEGROW) {
        auto &snakeIncrComp = static_cast<Snake::Component::SnakeGrow &>(snakeIncrIComp);
        if (eventManager.isEventTriggered(EATED_EVENT).first) {
            snakeIncrComp.grow += 1;
            snakeEntity->removeComponent(MUSIC_COMP + std::to_string(_id) + abc);
            _id++;
            std::string id = MUSIC_COMP + std::to_string(_id) + abc;
            auto music = std::make_shared<Arcade::Graph::Music>(id);
            music->loop = false;
            music->play = true;
            music->path = MUSIC_PATH_AWARD;
            snakeEntity->addComponent(music);
        }
    }
}
