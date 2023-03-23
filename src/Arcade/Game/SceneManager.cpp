/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

Arcade::Game::SceneManager::SceneManager()
{
}

Arcade::Game::SceneManager::~SceneManager()
{
}

void Arcade::Game::SceneManager::registerScene(const std::string &sceneName, std::unique_ptr<Arcade::Game::IScene> scene)
{
    this->_Scenes.emplace(sceneName, scene);
}

void Arcade::Game::SceneManager::changeScene(const std::string &sceneName)
{
    this->_CurrentScene = sceneName;
}

std::unique_ptr<Arcade::Game::IScene> &Arcade::Game::SceneManager::getCurrentScene()
{
    auto data = this->_Scenes.find(this->_CurrentScene);

    return (data->second);
}
