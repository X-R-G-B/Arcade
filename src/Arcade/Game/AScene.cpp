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
    return (*_EntityManager.get());
}
