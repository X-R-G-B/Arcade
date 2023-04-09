/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGrowSystem
*/

#include "Entity.hpp"
#include "SnakeCompType.hpp"
#include "Exceptions.hpp"
#include "SnakeGrow.hpp"
#include "Forward.hpp"
#include "MagicValue.hpp"
#include "SnakeGrowSystem.hpp"

Arcade::Graph::Sprite &Snake::System::SnakeGrowSystem::getSpriteFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity)
{
    auto &comp = entity->getComponents(Arcade::ECS::CompType::SPRITE);

    if (comp.size() == 0) {
        throw ArcadeExceptions("Can't get Sprite from body");
    }
    auto &body = static_cast<Arcade::Graph::Sprite &>(* (comp.at(0).get()));
    return body;
}

Snake::Component::Forward &Snake::System::SnakeGrowSystem::getMovableFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity)
{
    auto &comp = entity->getComponents(Arcade::ECS::CompType::FORWARD);

    if (comp.size() == 0) {
        throw ArcadeExceptions("Can't get Sprite from body");
    }
    auto &body = static_cast<Snake::Component::Forward &>(* (comp.at(0).get()));
    return body;
}

std::shared_ptr<Arcade::ECS::IEntity> Snake::System::SnakeGrowSystem::getLastBody(Arcade::ECS::IEntityManager &entityManager, int size)
{
    if (size == 0) {
        return entityManager.getEntitiesById(SNAKE_HEAD);
    }
    return entityManager.getEntitiesById(SNAKE_BODY_PART + std::to_string(size - 1));
}

Snake::Direction Snake::System::SnakeGrowSystem::getDirection(Arcade::Vector3f &lastBodyPos, Arcade::Vector3f pos)
{
    if (lastBodyPos.x < pos.x) {
        return Direction::LEFT;
    } else if (lastBodyPos.x > pos.x) {
        return Direction::RIGHT;
    } else if (lastBodyPos.y < pos.y) {
        return Direction::UP;
    }
    return Direction::DOWN;
}

void Snake::System::SnakeGrowSystem::placeNewBody(
    Arcade::ECS::IEntityManager &entityManager, std::shared_ptr<Snake::Component::Forward> &forward,
    Arcade::Graph::ISprite &newBody, int size)
{
    auto lastEntity = getLastBody(entityManager, size);
    auto &lastEntitySprite = getSpriteFromBodyEntity(lastEntity);
    auto &lastEntityMovable = getMovableFromBodyEntity(lastEntity);
    Arcade::Vector3f pos = {lastEntitySprite.pos.x, lastEntitySprite.pos.y, 0};

    if (lastEntityMovable.direction == Direction::UP) {
        pos.y += PARCELL_SIZE;
    } else if (lastEntityMovable.direction == Direction::RIGHT) {
        pos.x -= PARCELL_SIZE;
    } else if (lastEntityMovable.direction == Direction::DOWN) {
        pos.y -= PARCELL_SIZE;
    } else if (lastEntityMovable.direction == Direction::LEFT) {
        pos.x += PARCELL_SIZE;
    }
    if (pos.y < SNAKE_PADDING_WINDOW_Y) {
        pos.y += lastEntitySprite.rect.height;
        pos.x -= lastEntitySprite.rect.width;
        if (pos.x < SNAKE_PADDING_WINDOW_X) {
            pos.x += lastEntitySprite.rect.width * 2;
        }
    }
    if (pos.x < SNAKE_PADDING_WINDOW_X) {
        pos.x += lastEntitySprite.rect.width;
        pos.y -= lastEntitySprite.rect.height;
        if (pos.y < SNAKE_PADDING_WINDOW_Y) {
            pos.y += lastEntitySprite.rect.height * 2;
        }
    }
    if (pos.y >= MAP_BOTTOM) {
        pos.y -= lastEntitySprite.rect.height;
        pos.x += lastEntitySprite.rect.width;
        if (pos.x >= MAP_RIGHT) {
            pos.x -= lastEntitySprite.rect.width * 2;
        }
    }
    if (pos.x >= MAP_RIGHT) {
        pos.x -= lastEntitySprite.rect.width;
        pos.y += lastEntitySprite.rect.height;
        if (pos.y >= MAP_BOTTOM) {
            pos.y -= lastEntitySprite.rect.height * 2;
        }
    }
    forward->direction = getDirection(lastEntitySprite.pos, pos);
    newBody.pos = pos;
}

void Snake::System::SnakeGrowSystem::addNewBodyPartToSnake(Arcade::ECS::IEntityManager &entityManager, int idNbr)
{
    const std::string id = SNAKE_BODY_PART + std::to_string(idNbr);

    auto &entity = entityManager.createEntity(id);
    auto snake = entityManager.getEntitiesById(SNAKE);
    auto &growCompGrow = static_cast<Snake::Component::SnakeGrow &>(snake->getComponents(SNAKE_GROW_COMPONENT));
    auto forward = std::make_shared<Snake::Component::Forward>(FORWARD_KEY, Direction::RIGHT);
    entity.addComponent(std::make_shared<Arcade::Graph::Sprite>(SNAKE_SPRITE));
    auto &comp = entity.getComponents(SNAKE_SPRITE);
    auto &body = static_cast<Arcade::Graph::Sprite &>(comp);
    body.path = SNAKEBODYPATH;
    body.rect = {0, 0, PARCELL_SIZE, PARCELL_SIZE};
    body.currentRectIndex = 0;
    body.ttyData.defaultChar = "#####\n#####\n#####";
    body.ttyData.background = {255, 255, 255, 0};
    body.ttyData.foreground = {255, 255, 255, 0};
    placeNewBody(entityManager, forward, body, idNbr);
    entity.addComponent(forward);
    growCompGrow.lastIdBodyComp = id;
}

void Snake::System::SnakeGrowSystem::run(double deltaTime, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto comps = currentEntityManager.getComponentsByComponentType(Arcade::ECS::CompType::SNAKEGROW);

    if (comps->size() == 0) {
        throw ArcadeExceptions("can't find grow component");
    }
    auto bodyToIncr = std::static_pointer_cast<Snake::Component::SnakeGrow>(comps->at(0));

    for (; bodyToIncr->grow > 0 ; bodyToIncr->grow--, bodyToIncr->size++) {
        addNewBodyPartToSnake(currentEntityManager, bodyToIncr->size);
    }
}
