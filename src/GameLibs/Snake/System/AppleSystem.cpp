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

void Snake::System::AppleSystem::modifyApplePos(Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::shared_ptr<Arcade::ECS::IEntity> apple = currentEntityManager.getEntitiesById(APPLE_ENTITY);
    Arcade::ECS::IComponent &appleIComp = apple->getComponents(APPLE_SPRITE_COMP);
    auto snakeEntities = currentEntityManager.getEntitiesByComponentType(Arcade::ECS::CompType::MOVEABLE);
    std::size_t randNumber = 1 + (std::rand() % _positions.size());
    Arcade::Vector3f randPosition = _positions[randNumber];

    for (auto it = snakeEntities->begin(); it != snakeEntities->end(); it++) {
        auto entity = *it;
        auto components = entity->getComponents(Arcade::ECS::CompType::SPRITE).front();
        auto moveableSprite = static_pointer_cast<Arcade::Graph::Sprite>(components);

        if (moveableSprite->pos.x == randPosition.x && moveableSprite->pos.y == randPosition.y) {
            randPosition = _positions[1 + (std::rand() % _positions.size())];
            it = snakeEntities->begin();
            _positions.erase(std::next(_positions.begin(), randNumber));
        }
        if (_positions.size() <= 0) {
            eventManager.addEvent(RESTART_EVENT);
            return;
        }
    }
    if (appleIComp.type == Arcade::ECS::CompType::SPRITE) {
        Arcade::Graph::Sprite &appleComp = static_cast<Arcade::Graph::Sprite &>(appleIComp);
        appleComp.pos = randPosition;
    }
    _positions.clear();
}

void Snake::System::AppleSystem::run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto mapEntity = currentEntityManager.getEntitiesById(SNAKE_MAP_ID);
    auto mapComponents = mapEntity->getComponents(Arcade::ECS::CompType::SPRITE);

    if (!eventManager.isEventTriggered(EATED_EVENT).first) {
        return;
    }
    for (auto it = mapComponents.begin(); it != mapComponents.end(); it++) {
        auto comp = *it;
        auto spriteComp = std::static_pointer_cast<Arcade::Graph::Sprite>(comp);

        _positions.push_back(spriteComp->pos);
    }
    this->modifyApplePos(eventManager, currentEntityManager);
}
