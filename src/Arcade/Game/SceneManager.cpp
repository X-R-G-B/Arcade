/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include <memory>

Arcade::Game::SceneManager::SceneManager()
{
}

Arcade::Game::SceneManager::~SceneManager()
{
}

void Arcade::Game::SceneManager::registerScene(const std::string &sceneName, std::unique_ptr<Arcade::Game::IScene> scene)
{
    _Scenes[sceneName].swap(scene);
}

void Arcade::Game::SceneManager::changeScene(const std::string &sceneName)
{
    this->_CurrentScene = sceneName;
}

std::unique_ptr<Arcade::Game::IScene> &Arcade::Game::SceneManager::getCurrentScene()
{
    auto data = this->_Scenes.find(this->_CurrentScene);

    if (data != _Scenes.end()) {
        return (data->second);
    } else {
        throw std::__throw_runtime_error;
        //TODO change the error by the good one
    }
}
