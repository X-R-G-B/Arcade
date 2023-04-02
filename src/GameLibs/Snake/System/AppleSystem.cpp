/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AppleSystem
*/

#include "AppleSystem.hpp"
#include "Sprite.hpp"
#include "EntityManager.hpp"
#include "SnakeCompType.hpp"
#include "MagicValue.hpp"
#include "SnakeGrow.hpp"

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

void Snake::System::AppleSystem::modifyApplePos(Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &currentEntityManager, std::vector<Arcade::Vector3f> positions)
{
    std::shared_ptr<Arcade::ECS::IEntity> apple = currentEntityManager.getEntitiesById("Apple");
    Arcade::ECS::IComponent &appleIComp = apple->getComponents("apple");
    auto snakeEntities = currentEntityManager.getEntitiesByComponentType(Arcade::ECS::CompType::MOVEABLE);
    std::vector<Arcade::Vector3f> tempPositions = positions;
    std::size_t nbrOfPos = POS_OF_APPLE;
    std::size_t randNumber = 1 + (std::rand() % nbrOfPos);
    Arcade::Vector3f randPosition = positions[randNumber];

    for (auto it = snakeEntities->begin(); it != snakeEntities->end(); it++) {
        auto entity = *it;
        auto components = *(entity->getComponents(Arcade::ECS::CompType::SPRITE).begin());
        Arcade::Graph::Sprite &moveableSprite = static_cast<Arcade::Graph::Sprite &>(*components);

        if (moveableSprite.pos.x == randPosition.x && moveableSprite.pos.y == randPosition.y) {
            nbrOfPos -= 1;
            randPosition = positions[1 + (std::rand() % nbrOfPos)];
            it = snakeEntities->begin();
            positions.erase(std::next(positions.begin(), randNumber));
        }
        if (nbrOfPos < 0) {
            eventManager.addEvent("");
        }
    }
    if (appleIComp.type == Arcade::ECS::CompType::SPRITE) {
        Arcade::Graph::Sprite &appleComp = static_cast<Arcade::Graph::Sprite &>(appleIComp);
        appleComp.pos = randPosition;
    }
}

void Snake::System::AppleSystem::run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager)
{
    if (eventManager.isEventTriggered(EATED_EVENT).first) {
        this->modifyApplePos(eventManager, currentEntityManager, _positions);
    }
}
