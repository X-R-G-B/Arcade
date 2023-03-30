/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuScene
*/

#include "Text.hpp"
#include "MainMenuScene.hpp"

Arcade::Core::MainMenuScene::MainMenuScene(
    std::unique_ptr<Arcade::ECS::IEntityManager> enitityManager,
    const std::vector<std::pair<std::string, std::string>> &gameLibs,
    const std::vector<std::pair<std::string, std::string>> &graphicLibs
    )
    : AScene(std::move(enitityManager)), _gameLibs(gameLibs), _graphicLibs(graphicLibs)
{
}


//TODO when IDisplayModule is good, implement the good positions for texts

bool Arcade::Core::MainMenuScene::init()
{
    Arcade::ECS::IEntityManager &entityManager = getEntityManager();
    Arcade::ECS::IEntity &gamesEntity = entityManager.createEntity("Games");
    Arcade::ECS::IEntity &graphicsEntity = entityManager.createEntity("Graphics");
    std::shared_ptr<Arcade::Graph::Text> text = nullptr;
    Arcade::Vector3f compPos = {
        10, 20, 0
    };

    for (std::size_t i = 0; i != _gameLibs.size(); i++) {
        text = std::make_shared<Arcade::Graph::Text>(_gameLibs[i].first);
        text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
        text->text = _gameLibs[i].first;
        text->pos = compPos;
        compPos.x += 10;
        gamesEntity.addComponent(text);
    }
    compPos.y += 20;
    compPos.x = 0;
    for (std::size_t i = 0; i != _graphicLibs.size(); i++) {
        text = std::make_shared<Arcade::Graph::Text>(_graphicLibs[i].first);
        text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
        text->text = _graphicLibs[i].first;
        text->pos = compPos;
        compPos.x += 10;
        graphicsEntity.addComponent(text);
    }
    return (true);
}

void Arcade::Core::MainMenuScene::close()
{
    _EntityManager->removeAllEntities();
}
