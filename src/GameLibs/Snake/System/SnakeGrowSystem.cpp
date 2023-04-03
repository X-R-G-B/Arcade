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

Arcade::Graph::Sprite &Snake::SnakeGrowSystem::getSpriteFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity)
{
    auto &comp = entity->getComponents(Arcade::ECS::CompType::SPRITE);

    if (comp.size() == 0) {
        throw ArcadeExceptions("Can't get Sprite from body");
    }
    auto &body = static_cast<Arcade::Graph::Sprite &>(* (comp.at(0).get()));
    return body;
}

Snake::Component::Forward &Snake::SnakeGrowSystem::getMovableFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity)
{
    auto &comp = entity->getComponents(Arcade::ECS::CompType::FORWARD);

    if (comp.size() == 0) {
        throw ArcadeExceptions("Can't get Sprite from body");
    }
    auto &body = static_cast<Snake::Component::Forward &>(* (comp.at(0).get()));
    return body;
}

Arcade::Vector3f Snake::SnakeGrowSystem::getPositionForNewBody(Arcade::ECS::IEntityManager &currentScene)
{
    auto bodies = currentScene.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);
    auto lastEntity = currentScene.getEntitiesById("snake_body_part_" + std::to_string(bodies->size() - 1));
    auto &lastEntitySprite = getSpriteFromBodyEntity(lastEntity);
    auto &lastEntityMovable = getMovableFromBodyEntity(lastEntity);
    Arcade::Vector3f pos = {lastEntitySprite.pos.x, lastEntitySprite.pos.y, lastEntitySprite.pos.z};

    switch (lastEntityMovable.direction) {
        case Direction::UP:
            pos.y -= lastEntitySprite.rect.height;
        case Direction::RIGHT:
            pos.x -= lastEntitySprite.rect.width;
        case Direction::DOWN:
            pos.y += lastEntitySprite.rect.height;
        case Direction::LEFT:
            pos.x += lastEntitySprite.rect.width;
    }
    if (pos.y < 0) {
        pos.y += lastEntitySprite.rect.height;
        pos.x -= lastEntitySprite.rect.width;
        if (pos.x < 0) {
            pos.x += lastEntitySprite.rect.width * 2;
        }
    }
    if (pos.x < 0) {
        pos.x += lastEntitySprite.rect.width;
        pos.y -= lastEntitySprite.rect.height;
        if (pos.y < 0) {
            pos.y += lastEntitySprite.rect.height * 2;
        }
    }
    if (pos.y > SCREENSIZEY) {
        pos.y -= lastEntitySprite.rect.height;
        pos.x += lastEntitySprite.rect.width;
        if (pos.x > SCREENSIZEX) {
            pos.x -= lastEntitySprite.rect.width * 2;
        }
    }
    if (pos.y > SCREENSIZEX) {
        pos.x -= lastEntitySprite.rect.width;
        pos.y += lastEntitySprite.rect.height;
        if (pos.y > SCREENSIZEY) {
            pos.y -= lastEntitySprite.rect.height * 2;
        }
    }
    return pos;
}

void Snake::SnakeGrowSystem::addNewBodyPartToSnake(Arcade::ECS::IEntityManager &currentScene, int idNbr)
{
    const std::string id = "snake_body_part_" + std::to_string(idNbr);
    const std::string idSprite = id + "_sprite";

    currentScene.createEntity(id);
    auto entity = currentScene.getEntitiesById(id);
    entity->addComponent(std::make_shared<Arcade::Graph::Sprite>(idSprite));
    auto &comp = entity->getComponents(idSprite);
    auto &body = static_cast<Arcade::Graph::Sprite &>(comp);
    body.path = SNAKEBODYPATH;
    body.pos = getPositionForNewBody(currentScene);
    body.currentRectIndex = 0;
    body.ttyData.defaultChar = "#";
    body.ttyData.background = {0, 255, 255, 0};
    body.ttyData.foreground = {0, 255, 0, 0};
}

void Snake::SnakeGrowSystem::run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    auto comps = currentScene.getComponentsByComponentType(Arcade::ECS::CompType::SNAKEGROW);

    if (comps->size() == 0) {
        throw ArcadeExceptions("can't find grow component");
    }
    auto bodyToIncr = std::static_pointer_cast<Snake::Component::SnakeGrow>(comps->at(0));
    auto snake_bodies = currentScene.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);

    for (; bodyToIncr->grow > 0 ; bodyToIncr->grow--, bodyToIncr->size++) {
        addNewBodyPartToSnake(currentScene, bodyToIncr->size);
    }
}
