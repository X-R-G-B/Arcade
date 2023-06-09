/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AScene
*/

#include "AScene.hpp"

Arcade::Game::AScene::AScene(std::unique_ptr<Arcade::ECS::IEntityManager> enitityManager)
{
    this->_EntityManager.swap(enitityManager);
}

Arcade::ECS::IEntityManager &Arcade::Game::AScene::getEntityManager()
{
    return (*_EntityManager.get());
}
