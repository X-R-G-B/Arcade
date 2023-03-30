/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AppleSystem
*/

#include "AppleSystem.hpp"
#include "Sprite.hpp"

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

Snake::System::AppleSystem::~AppleSystem()
{
}

// TODO check the pos of snake for the apple because we don't want
// the apple to spawn on the snake

void modifyApplePos(Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::shared_ptr<Arcade::ECS::IEntity> apple = currentEntityManager.getEntitiesById("Apple");

    // ÇA COMPILE PAS BRICE ?!
    if (apple->type == Arcade::ECS::Sprite) {
        Arcade::Graph::Sprite &appleComp = static_cast<Arcade::Graph::Sprite &>(apple->getComponents("Apple"));
        appleComp.pos = _positions[1 + (std::rand() % 20)];
    }
}

void Snake::System::AppleSystem::run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager)
{
    if (eventManager.isEventTriggered("Eated apple").first) {
        modifyApplePos(currentEntityManager);
        // TODO increase of score when score is implemented
    }
}
