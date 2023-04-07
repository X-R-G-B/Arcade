/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EatSystem
*/

#include "EatSystem.hpp"
#include "NibblerCompType.hpp"
#include "MagicValue.hpp"
#include "SnakeGrow.hpp"

void Nibbler::System::EatSystem::run(double deltaTime,
                              Arcade::ECS::IEventManager &eventManager,
                              Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto snakeEntity = currentEntityManager.getEntitiesById(NIBBLER);
    auto &snakeIncrIComp = snakeEntity->getComponents(NIBBLER_GROW_COMPONENT);

    if (snakeIncrIComp.type == Arcade::ECS::CompType::SNAKEGROW) {
        auto &snakeIncrComp = static_cast<Nibbler::Component::SnakeGrow &>(snakeIncrIComp);
        if (eventManager.isEventTriggered(EATED_EVENT).first) {
            snakeIncrComp.grow += 1;
            //TODO increment the score when implemented
        }
    }
}
