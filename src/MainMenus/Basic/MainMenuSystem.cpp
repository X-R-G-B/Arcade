/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuSystem
*/

#include "Text.hpp"
#include "MainMenuSystem.hpp"
#include "MagickValueBasic.hpp"

BasicMenu::MainMenuSystem::MainMenuSystem(Arcade::MainMenu::Context *context)
    : _context(context)
{
}

void BasicMenu::MainMenuSystem::run(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    if (_initialized) {
        return;
    }
    auto gamesEntity = entityManager.getEntitiesById(GAME_ENTITY_NAME);
    auto graphicsEntity = entityManager.getEntitiesById(GRAPH_ENTITY_NAME);
    std::shared_ptr<Arcade::Graph::Text> text = nullptr;
    Arcade::Vector3f compPos = {10, 10, 0};

    compPos.y = 50;
    for (const auto &textText : _context->gameLibraries) {
        text = std::make_shared<Arcade::Graph::Text>(textText);
        text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
        text->text = textText;
            text->textColor = {255, 0, 0, 255};
        text->pos = compPos;
        compPos.y += 24;
        gamesEntity->addComponent(text);
    }
    compPos.x = 1920.0 / 2.0;
    compPos.y = 50;
    for (const auto &textText : _context->graphicalLibraries) {
        text = std::make_shared<Arcade::Graph::Text>(textText);
        text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
        text->text = textText;
        text->textColor = {255, 0, 0, 255};
        text->pos = compPos;
        compPos.y += 24;
        graphicsEntity->addComponent(text);
    }
    _initialized = true;
}
