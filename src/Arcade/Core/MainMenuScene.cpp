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
    const std::vector<std::pair<std::string, std::string>> gameLibs,
    const std::vector<std::pair<std::string, std::string>> graphicLibs
    )
    : AScene(std::move(enitityManager)), _gameLibs(gameLibs), _graphicLibs(graphicLibs)
{
}


bool Arcade::Core::MainMenuScene::init()
{
    Arcade::ECS::IEntityManager &entityManager = getEntityManager();
    Arcade::ECS::IEntity &gamesEntity = entityManager.createEntity("Games");
    Arcade::ECS::IEntity &graphicsEntity = entityManager.createEntity("Graphics");
    std::shared_ptr<Arcade::Graph::Text> text = nullptr;
    Arcade::Vector3f compPos = {
        10, 20, 0
    };

    std::cout << "Starting init" << std::endl;
    std::cout << "Init games" << std::endl;
    for (std::size_t i = 0; i != _gameLibs.size(); i++) {
        std::cout << _gameLibs[i].first << std::endl;
        text = std::make_shared<Arcade::Graph::Text>(_gameLibs[i].first);
        text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
        text->text = _gameLibs[i].first;
        text->pos = compPos;
        compPos.x += 10;
        gamesEntity.addComponent(text);
    }
    std::cout << "init graph" << std::endl;
    compPos.y += 20;
    for (std::size_t i = 0; i != _graphicLibs.size(); i++) {
        std::cout << _graphicLibs[i].first << std::endl;
        text = std::make_shared<Arcade::Graph::Text>(_graphicLibs[i].first);
        text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
        text->text = _graphicLibs[i].first;
        text->pos = compPos;
        compPos.x += 5;
        graphicsEntity.addComponent(text);
    }
    std::cout << "Menu is init correctly" << std::endl;
    return (true);
}

void Arcade::Core::MainMenuScene::close()
{

}