/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include "Api.hpp"
#include "Snake.hpp"
#include "Move.hpp"
#include <memory>

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
    _systemManager.addSystem("MoveSnake", std::make_unique<Snake::System::Move>(_snakeDirection));
}

void Snake::SnakeGameModule::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager.update(deltaTime, eventManager, getCurrentEntityManager());
}
