/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuScene
*/

#include <memory>
#include "EntityManager.hpp"
#include "Text.hpp"
#include "MainMenuScene.hpp"
#include "MagickValueBasic.hpp"

BasicMenu::MainMenuScene::MainMenuScene(Arcade::MainMenu::Context *context):
    AScene(std::make_unique<Arcade::ECS::EntityManager>()), _context(context)
{
}

//TODO when IDisplayModule is good, implement the good positions for texts

bool BasicMenu::MainMenuScene::init()
{
    Arcade::ECS::IEntityManager &entityManager = getEntityManager();
    Arcade::ECS::IEntity &gamesEntity = entityManager.createEntity(GAME_ENTITY_NAME);
    Arcade::ECS::IEntity &graphicsEntity = entityManager.createEntity(GRAPH_ENTITY_NAME);
    std::shared_ptr<Arcade::Graph::Text> text = nullptr;
    Arcade::Vector3f compPos = {10, 10, 0};

    text = std::make_shared<Arcade::Graph::Text>("GameLibsText");
    text->fontPath = PATH_FONT;
    text->text = "Game Libs availible:";
    text->textColor = {255, 0, 0, 255};
    text->pos = compPos;
    gamesEntity.addComponent(text);
    compPos.x = 1920.0 / 2.0;
    compPos.y = 10;
    text = std::make_shared<Arcade::Graph::Text>("GraphLibsText");
    text->fontPath = PATH_FONT;
    text->text = "Graphic Libs availible:";
    text->textColor = {255, 0, 0, 255};
    text->pos = compPos;
    graphicsEntity.addComponent(text);
    return (true);
}

void BasicMenu::MainMenuScene::close()
{
    _EntityManager->removeAllEntities();
}
