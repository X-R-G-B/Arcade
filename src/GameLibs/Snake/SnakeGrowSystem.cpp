/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGrowSystem
*/

#include "Entity.hpp"
#include "Sprite.hpp"
#include "CompType.hpp"
#include "Exceptions.hpp"
#include "SnakeGrowSystem.hpp"

static const std::string snakeBodyIncrId = "snake body incr";
static const Arcade::Graph::Sprite snakeBody = {"snake_body", "assets/snake_body.png", {0, 0, 32, 32}};
static const Arcade::Vector2f screenSize = {1920, 1080};

Arcade::Graph::Sprite &Snake::SnakeGrowSystem::getSpriteFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity)
{
    auto &comp = entity->getComponents(Arcade::ECS::CompType::SPRITE);
    if (comp.size() == 0) {
        throw ArcadeExceptions("Can't get Sprite from body");
    }
    auto &body = static_cast<Arcade::Graph::Sprite &>(* (comp.at(0).get()));
    return body;
}

bool Snake::SnakeGrowSystem::isInsideABody(std::vector<std::shared_ptr<Arcade::ECS::IEntity>> &bodies, Arcade::Vector3f &pos) {
    for (auto entity : bodies) {
        auto &body = getSpriteFromBodyEntity(entity);

        if (pos.x < body.pos.x || pos.x > body.pos.x + body.rect.width) {
            return false;
        }
        if (pos.y < body.pos.y || pos.y > body.pos.y + body.rect.height) {
            return false;
        }
    }
    return true;
}

Arcade::Vector3f Snake::SnakeGrowSystem::getPositionForNewBody(Arcade::ECS::IEntityManager &currentScene)
{
    auto bodies = currentScene.getEntitiesByComponentType(Arcade::ECS::CompType::SNAKE_BODY);
    auto lastEntity = currentScene.getEntitiesById("snake_body_part_" + std::to_string(bodies->size() - 1));
    auto &lastEntitySprite = getSpriteFromBodyEntity(lastEntity);
    Arcade::Vector3f pos = {lastEntitySprite.pos.x, lastEntitySprite.pos.y, lastEntitySprite.pos.z};

    pos.x += lastEntitySprite.rect.width;
    if (pos.x < screenSize.x && !isInsideABody(bodies, pos)) {
        return pos;
    }
    pos -= lastEntitySprite.rect.width * 2;
    if (pos.x > 0 && !isInsideABody(bodies, pos)) {
        return pos;
    }
    pos += lastEntitySprite.rect.width;
    pos += lastEntitySprite.rect.height;
    if (pos.y < screenSize.y && !isInsideABody(bodies, pos)) {
        return pos;
    }
    pos -= lastEntitySprite.rect.height * 2;
    return pos;
}

void Snake::SnakeGrowSystem::addNewBodyPartToSnake(Arcade::ECS::IEntityManager &currentScene, int idNbr)
{
    const std::string id = "snake_body_part_" + std::to_string(idNbr);
    const std::strind idSprite = id + "_sprite";

    currentScene.createEntity(id);
    auto entity = currentScene.getEntitiesById(id);
    entity->addComponent(std::make_shared<Arcade::Graph::Sprite>(idSprite));
    auto &comp = entity->getComponents(idSprite);
    auto &body = static_cast<Arcade::Graph::Sprite &>(comp);
    body.path = snakeBody.path;
    body.pos = getPositionForNewBody(currentScene);
    body.currentRectIndex = 0;
    body.ttyData.defaultChar = "#";
    body.ttyData.background = {0, 255, 255, 255};
    body.ttyData.foreground = {0, 255, 0, 255};
}

void Snake::SnakeGrowSystem::run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    auto entities = currentScene.getEntitiesById("snake");
    auto comp = entities->getComponents(snakeBodyIncrId);
    int toIncr = 0;
    int snakeBodySize = 0;
    auto &bodyToIncr = static_cast< /* Snake::SnakeBodyIncrComponent */ &>(comp);
    auto snake_bodies = currentScene.getEntitiesByComponentType(Arcade::ECS::CompType::SNAKE_BODY);

    toIncr = bodyToIncr.getToIncr();
    snakeBodySize = snake_bodies->size();
    for (int i = snakeBodySize; i < toIncr ; i--) {
        addNewBodyPartToSnake(currentScene, i);
    }
}
