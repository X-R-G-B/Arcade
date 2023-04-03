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
#include "SnakeGrow.hpp"
#include "SnakeCompType.hpp"
#include "Restart.hpp"
#include "HeadCollision.hpp"
#include "EatSystem.hpp"

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
    _scenes.front()->init();
    _systemManager.addSystem("MoveInput", std::make_unique<Snake::System::MoveInput>());
    _systemManager.addSystem("MoveForward", std::make_unique<Snake::System::MoveForward>());
    _systemManager.addSystem("Restart", std::make_unique<Snake::System::Restart>(_scenes.front()));
    _systemManager.addSystem("collisionSystem", std::make_unique<Snake::System::HeadCollision>());
    _systemManager.addSystem("Apple", std::make_unique<Snake::System::AppleSystem>(_scenes.front()->getEntityManager()));
    _systemManager.addSystem("EatSystem", std::make_unique<Snake::System::EatSystem>());
}

Arcade::ECS::IEntityManager &Snake::SnakeGameModule::getCurrentEntityManager()
{
    return _scenes.front()->getEntityManager();
}

void Snake::SnakeGameModule::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager.update(deltaTime, eventManager, getCurrentEntityManager());
}
