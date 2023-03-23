/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AScene
*/

#include "AScene.hpp"

Arcade::Game::AScene::AScene()
{
}

Arcade::ECS::IEntityManager &Arcade::Game::AScene::getEntityManager()
{
    return (this->_EntityManager);
}

Arcade::ECS::ISystemManager &Arcade::Game::AScene::getSystemManager()
{
    return (this->_SystemManager);
}
