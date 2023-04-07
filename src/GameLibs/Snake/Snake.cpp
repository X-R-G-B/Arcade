/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include <memory>
#include "InputsSystem.hpp"
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
#include "SnakeGrowSystem.hpp"
#include "MoveDirection.hpp"
#include "Score.hpp"

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
    _systemManager.addSystem("AMoveInput", std::make_unique<Snake::System::MoveInput>());
    _systemManager.addSystem("InputsSystem", std::make_unique<Snake::System::InputsSystem>());
    _systemManager.addSystem("MoveForward", std::make_unique<Snake::System::MoveForward>());
    _systemManager.addSystem("MoveDirection", std::make_unique<Snake::System::MoveDirection>());
    _systemManager.addSystem("Restart", std::make_unique<Snake::System::Restart>(_scenes.front()));
    _systemManager.addSystem("AAcollisionSystem", std::make_unique<Snake::System::HeadCollision>());
    _systemManager.addSystem("AppleGeneration", std::make_unique<Snake::System::AppleSystem>());
    _systemManager.addSystem("EatSystem", std::make_unique<Snake::System::EatSystem>());
    _systemManager.addSystem("AAGrowSystem", std::make_unique<Snake::System::SnakeGrowSystem>());
    _systemManager.addSystem("ZScoreSystem", std::make_unique<Snake::System::Score>());
}

Arcade::ECS::IEntityManager &Snake::SnakeGameModule::getCurrentEntityManager()
{
    return _scenes.front()->getEntityManager();
}

void Snake::SnakeGameModule::update(double deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager.update(deltaTime, eventManager, getCurrentEntityManager());
}
