/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Score
*/

#include <sstream>
#include <string>
#include "Score.hpp"
#include "SnakeGrow.hpp"
#include "MagicValue.hpp"
#include "Text.hpp"

void Snake::System::Score::run(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &currentEntityManager)
{
    _float += deltaTime;
    if (_float < 1.6) {
        return;
    }
    _float -= 10;
    auto &grow = currentEntityManager.getEntitiesById(SNAKE)->getComponents(SNAKE_GROW_COMPONENT);
    auto scores = currentEntityManager.getEntitiesById(SCORE_ENTITY);
    auto &scoreCur = static_cast<Arcade::Graph::Text &>(scores->getComponents(SCORE_ENTITY_COMP_CURRENT));
    auto &scoreMax = static_cast<Arcade::Graph::Text &>(scores->getComponents(SCORE_ENTITY_COMP_MAX));
    auto &growComp = static_cast<Snake::Component::SnakeGrow &>(grow);
    std::stringstream ss;
    std::string str;
    int Score;

    scoreCur.text = "Current Score: " + std::to_string(growComp.size);
    str = scoreMax.text.substr(scoreMax.text.find(": ") + 2, scoreMax.text.npos);
    if (str.empty()) {
        return;
    }
    ss << str;
    ss >> Score;
    if (Score < growComp.size) {
        scoreMax.text = "Max Score: " + std::to_string(growComp.size);
    }
}
