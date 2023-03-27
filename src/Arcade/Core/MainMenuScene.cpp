/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuScene
*/

#include "Text.hpp"
#include "MainMenuScene.hpp"

Arcade::Core::MainMenuScene::MainMenuScene(std::unique_ptr<Arcade::ECS::IEntityManager> enitityManager)
    : AScene(std::move(enitityManager))
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
    const std::vector<std::string> games = {
        "arcade_snake", "arcade_nibbler", "arcade_pacman",
        "arcade_qix", "arcade_centipede", "arcade_solarfox"
    };
    const std::vector<std::string> graphics = {
        "arcade_ndk++", "arcade_aalib", "arcade_libcaca",
        "arcade_allegro5", "arcade_xlib", "arcade_gtk",
        "arcade_sfml", "arcade_irrlicht", "arcade_opengl",
        "arcade_vulkan", "arcade_qt5"
    };

    std::cout << "Starting init" << std::endl;
    for (std::size_t i = 0; i != games.size(); i++) {
        std::cout << games[i] << std::endl;
        text = std::make_shared<Arcade::Graph::Text>(games[i]);
        text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
        text->text = games[i];
        text->pos = compPos;
        compPos.x += 10;
        gamesEntity.addComponent(text);
    }
    compPos.y += 20;
    for (std::size_t i = 0; i != graphics.size(); i++) {
        std::cout << graphics[i] << std::endl;
        text = std::make_shared<Arcade::Graph::Text>(graphics[i]);
        text->fontPath = "./assets/Menu/Roboto-Thin.ttf";
        text->text = graphics[i];
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