/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#include <memory>
#include "GameScene.hpp"
#include "Sprite.hpp"
#include "EntityManager.hpp"
#include "MagicValue.hpp"
#include "HeadCollision.hpp"
#include "Forward.hpp"
#include "SnakeGrow.hpp"
#include "SnakeMapComponent.hpp"

#define APPLE_SPRITE_COMP_PATH "assets/snake/normal/apple.png"

Snake::Scene::GameScene::GameScene()
    : Arcade::Game::AScene(std::make_unique<Arcade::ECS::EntityManager>())
{
}

void Snake::Scene::GameScene::addSnakeHeadSprite(Arcade::ECS::IEntity &head)
{
    std::shared_ptr<Arcade::Graph::Sprite> headS = std::make_shared<Arcade::Graph::Sprite>(SNAKE_SPRITE);

    headS->path = SNAKE_HEAD_PATH;
    headS->pos = {SNAKE_PADDING_WINDOW_X + PARCELL_SIZE * 5, SNAKE_PADDING_WINDOW_Y + PARCELL_SIZE * 8, 0};
    headS->rect = {0, 0, PARCELL_SIZE, PARCELL_SIZE};
    headS->currentRectIndex = 0;
    headS->ttyData.defaultChar = "#";
    headS->ttyData.background = {0, 0, 255, 0};
    headS->ttyData.foreground = {150, 0, 0, 0};
    head.addComponent(headS);
    head.addComponent(std::make_shared<Component::Forward>(FORWARD_KEY, Direction::RIGHT));
}

void Snake::Scene::GameScene::addSnakeMap()
{
    Arcade::ECS::IEntityManager &EntityManager = getEntityManager();
    Arcade::ECS::IEntity &snakeMap = EntityManager.createEntity(SNAKE_MAP_ID);
    int snakeMapParcelNbr = 0;
    bool darkColor = true;

    for (int y = 0; y < MAP_PARCELLS_Y; y++, snakeMapParcelNbr++) {
        for (int x = 0; x < MAP_PARCELLS_X; x++, snakeMapParcelNbr++) {
            snakeMap.addComponent(
            std::make_shared<Snake::Component::SnakeMapComponent>(
            std::string(SNAKE_MAP_ID) + "_" + std::to_string(snakeMapParcelNbr),
            Arcade::Vector3f(SNAKE_PADDING_WINDOW_X + x * PARCELL_SIZE, SNAKE_PADDING_WINDOW_Y + y * PARCELL_SIZE, 0), darkColor));
            darkColor = (darkColor) ? false : true;
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
    grow.grow = 0;
    addSnakeHeadSprite(head);
}

void Snake::Scene::GameScene::createApple()
{
    Arcade::ECS::IEntityManager &entityManager = getEntityManager();
    Arcade::ECS::IEntity &appleEntity = entityManager.createEntity(APPLE_ENTITY);
    std::shared_ptr<Arcade::Graph::Sprite> apple = std::make_shared<Arcade::Graph::Sprite>(APPLE_SPRITE_COMP);

    apple->ttyData = {"*", {255, 0, 0, 255}, {255, 0, 0, 255}};
    apple->path = APPLE_SPRITE_COMP_PATH;
    apple->pos = {SNAKE_PADDING_WINDOW_X + PARCELL_SIZE * 10, SNAKE_PADDING_WINDOW_Y + 8 * PARCELL_SIZE, 0};
    apple->rect = {0, 0, PARCELL_SIZE, PARCELL_SIZE};
    apple->currentRectIndex = 0;
    appleEntity.addComponent(apple);
}

bool Snake::Scene::GameScene::init()
{
    addSnakeMap();
    createApple();
    createSnake();
    return (true);
}

void Snake::Scene::GameScene::close()
{
    this->getEntityManager().removeAllEntities();
}
