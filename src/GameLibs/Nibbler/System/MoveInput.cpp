/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#include <map>
#include <string>
#include <vector>
#include "ArcadeStruct.hpp"
#include "ISprite.hpp"
#include "Direction.hpp"
#include "Forward.hpp"
#include "MoveInput.hpp"
#include "MagicValue.hpp"
#include "ChangeDir.hpp"

static const std::map<Nibbler::Direction, std::vector<std::pair<std::string, Nibbler::Direction>>>
directionsChoice = {
    {
        Nibbler::Direction::UP, {
            std::make_pair("KEY_LEFT_PRESSED", Nibbler::Direction::LEFT),
            std::make_pair("KEY_RIGHT_PRESSED", Nibbler::Direction::RIGHT),
        }
    },
    {
        Nibbler::Direction::DOWN, {
            std::make_pair("KEY_LEFT_PRESSED", Nibbler::Direction::LEFT),
            std::make_pair("KEY_RIGHT_PRESSED", Nibbler::Direction::RIGHT),
        }
    },
    {
        Nibbler::Direction::RIGHT, {
            std::make_pair("KEY_UP_PRESSED", Nibbler::Direction::UP),
            std::make_pair("KEY_DOWN_PRESSED", Nibbler::Direction::DOWN),
        }
    },
    {
        Nibbler::Direction::LEFT, {
            std::make_pair("KEY_UP_PRESSED", Nibbler::Direction::UP),
            std::make_pair("KEY_DOWN_PRESSED", Nibbler::Direction::DOWN),
        }
    }
};

Arcade::Vector2f Nibbler::System::MoveInput::toNextCase(const Arcade::Vector3f &pos, const Nibbler::Direction &direction)
{
    int caseCurX = (TO_INT(pos.x) - NIBBLER_PADDING_WINDOW_X) / PARCELL_SIZE;
    int caseCurY = (TO_INT(pos.y) - NIBBLER_PADDING_WINDOW_Y) / PARCELL_SIZE;

    if (direction == Direction::UP) {
        return {pos.x, caseCurY * TO_FLOAT(PARCELL_SIZE) + NIBBLER_PADDING_WINDOW_Y};
    } else if (direction == Direction::DOWN) {
        caseCurY = (TO_INT(pos.y) + PARCELL_SIZE - NIBBLER_PADDING_WINDOW_Y) / PARCELL_SIZE;
        return {pos.x, caseCurY * TO_FLOAT(PARCELL_SIZE) + NIBBLER_PADDING_WINDOW_Y};
    } else if (direction == Direction::LEFT) {
        return {caseCurX * TO_FLOAT(PARCELL_SIZE) + NIBBLER_PADDING_WINDOW_X, pos.y};
    } else if (direction == Direction::RIGHT) {
        caseCurX = (TO_INT(pos.x) + PARCELL_SIZE - NIBBLER_PADDING_WINDOW_X) / PARCELL_SIZE;
        return {caseCurX * TO_FLOAT(PARCELL_SIZE) + NIBBLER_PADDING_WINDOW_X, pos.y};
    }
    return {pos.x, pos.y};
}

void Nibbler::System::MoveInput::run(
    double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    static int nb_move = 0;
    auto head = currentEntityManager.getEntitiesById(NIBBLER_HEAD);
    auto &curDir = static_cast<Component::Forward &>(head->getComponents(FORWARD_KEY));
    auto &sprite = static_cast<Arcade::Graph::ISprite &>(head->getComponents(NIBBLER_SPRITE));

    for (auto &[event, action] : directionsChoice.at(curDir.direction)) {
        if (eventManager.isEventTriggered(event).first) {
            auto pos = toNextCase(sprite.pos, curDir.direction);
            head->addComponent(std::make_shared<Component::ChangeDir>(
                MOVE_INPUT_COMPS + std::to_string(++nb_move),
                action,
                pos
            ));
            break;
        }
    }
}
