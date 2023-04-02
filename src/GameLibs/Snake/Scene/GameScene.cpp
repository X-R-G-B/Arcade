/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#include <iostream>
#include <memory>
#include "GameScene.hpp"
#include "Sprite.hpp"
#include "EntityManager.hpp"
#include "MagicValue.hpp"

Snake::Scene::GameScene::GameScene()
    : Arcade::Game::AScene(std::make_unique<Arcade::ECS::EntityManager>())
{
}

bool Snake::Scene::GameScene::init()
{
    Arcade::ECS::IEntityManager &entityManager = this->getEntityManager();
    Arcade::ECS::IEntity &appleEntity = entityManager.createEntity(APPLE_ENTITY);
    std::shared_ptr<Arcade::Graph::Sprite> apple = nullptr;
    Arcade::Vector3f applePosition = {
        30, 30, 0
    };

    apple = std::make_shared<Arcade::Graph::Sprite>(APLLE_SPRITE_COMP);
    apple->ttyData = {"*", {255, 0, 0, 255}, {255, 0, 0, 255}};
    apple->path = APLLE_SPRITE_COMP_PATH;
    apple->pos = applePosition;
    apple->rect = {0, 0, 200, 200};
    apple->currentRectIndex = 0;
    return (true);
}

void Snake::Scene::GameScene::close()
{
    this->_EntityManager.removeAllEntities();
}
