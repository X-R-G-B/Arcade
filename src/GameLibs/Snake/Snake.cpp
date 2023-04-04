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
#include "MagicValue.hpp"
#include "HeadCollision.hpp"
#include "SnakeMapComponent.hpp"

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
    std::shared_ptr<Arcade::Graph::Sprite> headS = std::make_shared<Arcade::Graph::Sprite>(SNAKE_HEAD_SPRITE_COMP);

    headS->path = SNAKE_HEAD_PATH;
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
    head.addComponent(headS);
    head.addComponent(std::make_shared<Component::Forward>(FORWARD_KEY, Direction::RIGHT));
}

void Snake::SnakeGameModule::addSnakeMap()
{
    int snakeMapParcelNbr = 0;

    Arcade::ECS::IEntityManager &EntityManager = _scenes.front()->getEntityManager();
    Arcade::ECS::IEntity &snakeMap = EntityManager.createEntity(SNAKE_MAP_ID);
    for (int y = 0; y < NBR_OF_PARCELS_IN_LINE; y++, snakeMapParcelNbr++) {
        for (int x = 0; x < NBR_OF_PARCELS_IN_LINE; x++, snakeMapParcelNbr++) {
            snakeMap.addComponent(
            std::make_shared<Snake::Component::SnakeMapComponent>(
            std::string(SNAKE_MAP_ID) + "_" + std::to_string(snakeMapParcelNbr),
            Arcade::Vector3f(SNAKE_PADDING_WINDOW_X + x * SNAKE_MAP_SIZE, SNAKE_PADDING_WINDOW_Y + y * SNAKE_MAP_SIZE, 0)));
        }
    }
}

void Snake::SnakeGameModule::createSnake()
{
    Arcade::ECS::IEntityManager &EntityManager = _scenes.front()->getEntityManager();
    Arcade::ECS::IEntity &snake = EntityManager.createEntity(SNAKE);
    Arcade::ECS::IEntity &head = EntityManager.createEntity(SNAKE_HEAD);
    Arcade::ECS::IEntity &map = EntityManager.createEntity(SNAKE_MAP_ID);

    snake.addComponent(std::make_shared<Component::SnakeGrow>(SNAKE_GROW_COMPONENT));
    addSnakeHeadSprite(head);
}

Snake::SnakeGameModule::SnakeGameModule()
{
    _scenes.push_back(std::make_unique<Snake::Scene::GameScene>());
    _scenes.front()->init();
    _systemManager.addSystem("Apple", std::make_unique<Snake::System::AppleSystem>());
    _systemManager.addSystem("MoveInput", std::make_unique<Snake::System::MoveInput>());
    _systemManager.addSystem("MoveForward", std::make_unique<Snake::System::MoveForward>());
    _systemManager.addSystem("Restart", std::make_unique<Snake::System::Restart>(_scenes.front()));
    createSnake();
    _systemManager.addSystem("collisionSystem", std::make_unique<Snake::System::HeadCollision>());
}

Arcade::ECS::IEntityManager &Snake::SnakeGameModule::getCurrentEntityManager()
{
    return _scenes.front()->getEntityManager();
}

void Snake::SnakeGameModule::update(double deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager.update(deltaTime, eventManager, getCurrentEntityManager());
}
