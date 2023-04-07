/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include "Restart.hpp"
#include "MagicValue.hpp"
#include "SnakeGrow.hpp"
#include "SaveScore.hpp"

Snake::System::Restart::Restart(std::unique_ptr<Arcade::Game::IScene> &scene) : _scene(scene)
{
}

void Snake::System::Restart::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    if (!eventManager.isEventTriggered(RESTART_EVENT).first) {
        return;
    }
    auto snake = currentEntityManager.getEntitiesById(SNAKE);
    try {
        auto &growCompGrow = static_cast<Snake::Component::SnakeGrow &>(snake->getComponents(SNAKE_GROW_COMPONENT));
        SaveScore::SaveScore saveScore(PATH_SCORE);
        auto score = saveScore.loadScore();
        if (score.find(SAVE_SCORE_NAME) == score.end()) {
            score[SAVE_SCORE_NAME] = std::to_string(growCompGrow.size);
        } else {
            std::stringstream ss(score.at(SAVE_SCORE_NAME));
            int res;
            ss >> res;
            score[SAVE_SCORE_NAME] = std::to_string(std::max(res, growCompGrow.size));
        }
        saveScore.saveScore(score);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Could not get what is necessary to write score!" << std::endl;
    }
    _scene->close();
    _scene->init();
}
