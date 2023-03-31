/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include <memory>
#include "Api.hpp"
#include "Snake.hpp"
#include "MoveInput.hpp"
#include "MoveForward.hpp"
#include "GameScene.hpp"
#include "AppleSystem.hpp"

extern "C" {
    LibType getType()
    {
        return LibType::GAME;
    }

    const char *getName()
    {
        return "Snake";
    }

    Arcade::Game::IGameModule *getGameModule()
    {
        return new Snake::SnakeGameModule();
    }

    void destroyGameModule(Arcade::Game::IGameModule *gameModule)
    {
        delete gameModule;
    }
}

Snake::SnakeGameModule::SnakeGameModule()
{
    _scenes.push_back(std::make_unique<Snake::Scene::GameScene>());
    _systemManager.addSystem("Apple", std::make_unique<Snake::System::AppleSystem>());
    _systemManager.addSystem("MoveInput", std::make_unique<Snake::System::MoveInput>());
    _systemManager.addSystem("MoveForward", std::make_unique<Snake::System::MoveForward>());
}

void Snake::SnakeGameModule::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager.update(deltaTime, eventManager, getCurrentEntityManager());
}
