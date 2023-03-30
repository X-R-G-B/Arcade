/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#include <iostream>
#include "GameScene.hpp"
#include "Sprite.hpp"

Snake::Scene::GameScene::GameScene(std::unique_ptr<Arcade::ECS::IEntityManager> enitityManager)
    : Arcade::Game::AScene(std::move(enitityManager))
{
}

bool Snake::Scene::GameScene::init()
{
    Arcade::ECS::IEntityManager &entityManager = this->getEntityManager();
    Arcade::ECS::IEntity &appleEntity = entityManager.createEntity("Apple");
    std::shared_ptr<Arcade::Graph::Sprite> apple = nullptr;
    Arcade::Vector3f applePosition = {
        30, 30, 0
    };

    apple = std::make_shared<Arcade::Graph::Sprite>("apple");
    apple->ttyData = {"*", {255, 0, 0, 255}, {255, 0, 0, 255}};
    apple->path = "assets/Snake/apple.png";
    apple->pos = applePosition;
    apple->rect = {0, 0, 200, 200};
    apple->currentRectIndex = 0;
    return (true);
}

void Snake::Scene::GameScene::close()
{
    _EntityManager->removeAllEntities();
}
