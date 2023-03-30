/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AppleSystem
*/

#include "AppleSystem.hpp"
#include "Sprite.hpp"
#include "CompType.hpp"

Snake::System::AppleSystem::AppleSystem()
{
    Arcade::Vector3f pos = {
        0, 0, 0
    };

    for (std::size_t it = 0; it != 20; it++) {
        pos.x += 5;
        pos.y += 5;
        _positions.insert(_positions.begin(), pos);
    }
}

// TODO check the pos of snake for the apple because we don't want
// the apple to spawn on the snake

void modifyApplePos(Arcade::ECS::IEntityManager &currentEntityManager, std::vector<Arcade::Vector3f> positions)
{
    std::shared_ptr<Arcade::ECS::IEntity> apple = currentEntityManager.getEntitiesById("Apple");
    Arcade::ECS::IComponent &appleIComp = apple->getComponents("apple");

    if (appleIComp.type == Arcade::ECS::CompType::SPRITE) {
        Arcade::Graph::Sprite &appleComp = static_cast<Arcade::Graph::Sprite &>(appleIComp);
        appleComp.pos = positions[1 + (std::rand() % 20)];
    }
}

void Snake::System::AppleSystem::run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager)
{
    if (eventManager.isEventTriggered("Eated apple").first) {
        modifyApplePos(currentEntityManager, _positions);
        eventManager.clearEvents();
        // TODO increase of score when score is implemented
    }
}
