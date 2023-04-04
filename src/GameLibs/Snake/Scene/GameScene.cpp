/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#include <iostream>
#include <memory>
#include "GameScene.hpp"
#include "Sprite.hpp"
#include "EntityManager.hpp"
#include "MagicValue.hpp"
#include "HeadCollision.hpp"
#include "Forward.hpp"
#include "SnakeGrow.hpp"
#include "SnakeMapComponent.hpp"

#define APPLE_SPRITE_COMP_PATH "assets/Snake/apple.png"

Snake::Scene::GameScene::GameScene()
    : Arcade::Game::AScene(std::make_unique<Arcade::ECS::EntityManager>())
{
}

void Snake::Scene::GameScene::addSnakeHeadSprite(Arcade::ECS::IEntity &head)
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

void Snake::Scene::GameScene::addSnakeMap()
{
    Arcade::ECS::IEntityManager &EntityManager = getEntityManager();
    Arcade::ECS::IEntity &snakeMap = EntityManager.createEntity(SNAKE_MAP_ID);
    int snakeMapParcelNbr = 0;

    for (int y = 0; y < NBR_OF_PARCELS_IN_LINE; y++, snakeMapParcelNbr++) {
        for (int x = 0; x < NBR_OF_PARCELS_IN_LINE; x++, snakeMapParcelNbr++) {
            snakeMap.addComponent(
            std::make_shared<Snake::Component::SnakeMapComponent>(
            std::string(SNAKE_MAP_ID) + "_" + std::to_string(snakeMapParcelNbr),
            Arcade::Vector3f(SNAKE_PADDING_WINDOW_X + x * SNAKE_MAP_SIZE, SNAKE_PADDING_WINDOW_Y + y * SNAKE_MAP_SIZE, 0)));
        }
    }
}

void Snake::Scene::GameScene::createSnake()
{
    Arcade::ECS::IEntityManager &EntityManager = getEntityManager();
    Arcade::ECS::IEntity &snake = EntityManager.createEntity(SNAKE);
    Arcade::ECS::IEntity &head = EntityManager.createEntity(SNAKE_HEAD);

    snake.addComponent(std::make_shared<Component::SnakeGrow>(SNAKE_GROW_COMPONENT));
    Snake::Component::SnakeGrow &grow = static_cast<Snake::Component::SnakeGrow&>(snake.getComponents(SNAKE_GROW_COMPONENT));
    grow.grow = 4;
    addSnakeHeadSprite(head);
}

void Snake::Scene::GameScene::createApple()
{
    Arcade::ECS::IEntityManager &entityManager = getEntityManager();
    Arcade::ECS::IEntity &appleEntity = entityManager.createEntity(APPLE_ENTITY);
    std::shared_ptr<Arcade::Graph::Sprite> apple = std::make_shared<Arcade::Graph::Sprite>(APPLE_SPRITE_COMP);
    Arcade::Vector3f applePosition = {
        30, 30, 0
    };

    apple->ttyData = {"*", {255, 0, 0, 255}, {255, 0, 0, 255}};
    apple->path = APPLE_SPRITE_COMP_PATH;
    apple->pos = {600, 400, 0};
    apple->rect = {0, 0, 128, 128};
    apple->currentRectIndex = 0;
    appleEntity.addComponent(apple);
}

bool Snake::Scene::GameScene::init()
{
    createApple();
    createSnake();
    addSnakeMap();
    return (true);
}

void Snake::Scene::GameScene::close()
{
    this->getEntityManager().removeAllEntities();
}
