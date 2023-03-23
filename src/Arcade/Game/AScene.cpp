/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AScene
*/

#include "AScene.hpp"

Arcade::Game::AScene::AScene(std::shared_ptr<ECS::ISystemManager> sysManager,
    std::shared_ptr<ECS::IEntityManager> entManager)
{
    _SystemManager = sysManager;
    _EntityManager = entManager;
}

const std::shared_ptr<Arcade::ECS::IEntityManager> &Arcade::Game::AScene::getEntityManager()
{
    return (this->_EntityManager);
}

const std::shared_ptr<Arcade::ECS::ISystemManager> &Arcade::Game::AScene::getSystemManager()
{
    return (this->_SystemManager);
}
