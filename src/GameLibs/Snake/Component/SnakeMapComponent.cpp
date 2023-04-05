/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** SnakeMapComponent
*/

#include "GraphStruct.hpp"
#include "SnakeMapComponent.hpp"

static const std::string defaultChar = "~~~\n~~~";
static const Arcade::Graph::Color foregroundColorDark(0, 180, 0, 0);
static const Arcade::Graph::Color backgroundColorDark(0, 180, 0, 0);
static const Arcade::Graph::Color foregroundColorBright(0, 160, 0, 0);
static const Arcade::Graph::Color backgroundColorBright(0, 160, 0, 0);

#define DARK_PARCELL "assets/snake/normal/bg_green_01.png"
#define LIGHT_PARCELL "assets/snake/normal/bg_green_02.png"
#define DEFAULT_CHAR "~~\n~~"

Snake::Component::SnakeMapComponent::SnakeMapComponent(const std::string &id, const Arcade::Vector3f &pos, bool darkColor)
    : Arcade::Graph::Sprite(id)
{
    this->type = Arcade::ECS::CompType::SPRITE;
    this->rect = {0, 0, PARCELL_SIZE, PARCELL_SIZE};
    if (darkColor) {
        this->path = DARK_PARCELL;
        this->ttyData = {DEFAULT_CHAR, foregroundColorDark, backgroundColorDark};
    } else {
        this->path = LIGHT_PARCELL;
        this->ttyData = {DEFAULT_CHAR, foregroundColorBright, backgroundColorBright};
    }
    this->currentRectIndex = 0;
    this->pos = pos;
}
