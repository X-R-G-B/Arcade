/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include <memory>
#include "Api.hpp"
#include "Snake.hpp"
#include "Move.hpp"
#include "GameScene.hpp"
#include "AppleSystem.hpp"
#include "Moveable.hpp"
#include "SnakeGrow.hpp"
#include "SnakeCompType.hpp"

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

void Snake::SnakeGameModule::addSnakeHeadSprite(Arcade::ECS::IEntity &head)
{
    std::shared_ptr<Arcade::Graph::Sprite> headS = std::make_shared<Arcade::Graph::Sprite>("sprite");

    headS->path = "./assets/Snake/head/";
    //supposed values for instance
    headS->pos.x = 200;
    headS->pos.y = 200;
    headS->pos.z = 0;
    headS->rect.left = 0;
    headS->rect.top = 0;
    headS->rect.width = 20;
    headS->rect.height = 20;
    headS->currentRectIndex = 0;
    //TODO set tty data after snake sprite
    head.addComponent(std::make_shared<Component::Moveable>("dir", Direction::RIGHT));
}

void Snake::SnakeGameModule::createSnake()
{
    Arcade::ECS::IEntityManager &EntityManager = _scenes.front()->getEntityManager();
    Arcade::ECS::IEntity &snake = EntityManager.createEntity("snake");
    Arcade::ECS::IEntity &head = EntityManager.createEntity("head");

    snake.addComponent(std::make_shared<Component::SnakeGrow>("snakegrow"));
    addSnakeHeadSprite(head);
}

Snake::SnakeGameModule::SnakeGameModule()
{
    _scenes.push_back(std::make_unique<Snake::Scene::GameScene>());
    _scenes.front()->init();
    _systemManager.addSystem("Apple", std::make_unique<Snake::System::AppleSystem>());
    _systemManager.addSystem("MoveSnake", std::make_unique<Snake::System::Move>(_snakeDirection));
    createSnake();
}

void Snake::SnakeGameModule::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager.update(deltaTime, eventManager, getCurrentEntityManager());
}