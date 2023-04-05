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

BasicMenu::MainMenuScene::MainMenuScene(Arcade::MainMenu::Context *context):
    AScene(std::make_unique<Arcade::ECS::EntityManager>()), _context(context)
{
}

//TODO when IDisplayModule is good, implement the good positions for texts

bool BasicMenu::MainMenuScene::init()
{
    Arcade::ECS::IEntityManager &entityManager = getEntityManager();
    Arcade::ECS::IEntity &gamesEntity = entityManager.createEntity("Games");
    Arcade::ECS::IEntity &graphicsEntity = entityManager.createEntity("Graphics");
    std::shared_ptr<Arcade::Graph::Text> text = nullptr;
    Arcade::Vector3f compPos = {10, 10, 0};

    text = std::make_shared<Arcade::Graph::Text>("GameLibsText");
    text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
    text->text = "Game Libs availible:";
    text->textColor = {255, 0, 0, 255};
    text->pos = compPos;
    gamesEntity.addComponent(text);
    compPos.y = 50;
    for (const auto &textText : _context->gameLibraries) {
        text = std::make_shared<Arcade::Graph::Text>(textText);
        text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
        text->text = textText;
            text->textColor = {255, 0, 0, 255};
        text->pos = compPos;
        compPos.y += 24;
        gamesEntity.addComponent(text);
    }
    compPos.x = 1920.0 / 2.0;
    compPos.y = 10;
    text = std::make_shared<Arcade::Graph::Text>("GraphLibsText");
    text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
    text->text = "Graphic Libs availible:";
    text->textColor = {255, 0, 0, 255};
    text->pos = compPos;
    gamesEntity.addComponent(text);
    compPos.y = 50;
    for (const auto &textText : _context->graphicalLibraries) {
        text = std::make_shared<Arcade::Graph::Text>(textText);
        text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
        text->text = textText;
        text->textColor = {255, 0, 0, 255};
        text->pos = compPos;
        compPos.y += 24;
        graphicsEntity.addComponent(text);
    }
    return (true);
}

void BasicMenu::MainMenuScene::close()
{
    _EntityManager->removeAllEntities();
}
