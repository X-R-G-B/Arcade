/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#include <iostream>
#include "GameScene.hpp"

Snake::Scene::GameScene::GameScene(std::unique_ptr<Arcade::ECS::IEntityManager> enitityManager)
    : Arcade::Game::AScene(std::move(enitityManager))
{
}

bool Snake::Scene::GameScene::init()
{
    return (true);
}

void Snake::Scene::GameScene::close()
{
    _EntityManager->removeAllEntities();
}