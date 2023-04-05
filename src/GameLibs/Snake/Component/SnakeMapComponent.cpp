/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** SnakeMapComponent
*/

#include "GraphStruct.hpp"
#include "SnakeMapComponent.hpp"

static const std::string defaultChar = "~";
static const Arcade::Graph::Color foregroundColor(0, 180, 0, 0);
static const Arcade::Graph::Color backgroundColor(0, 180, 0, 0);

#define DARK_PARCELL "assets/snake/normal/bg_green_01.png"
#define LIGHT_PARCELL "assets/snake/normal/bg_green_02.png"
#define DEFAULT_CHAR "~"

Snake::Component::SnakeMapComponent::SnakeMapComponent(const std::string &id, const Arcade::Vector3f &pos, bool darkColor)
    : Arcade::Graph::Sprite(id)
{
    this->type = Arcade::ECS::CompType::SPRITE;
    this->rect = {0, 0, PARCELL_SIZE, PARCELL_SIZE};
    if (darkColor) {
        this->path = DARK_PARCELL;
    } else {
        this->path = LIGHT_PARCELL;
    }
    this->currentRectIndex = 0;
    this->pos = pos;
    this->ttyData = {DEFAULT_CHAR, foregroundColor, backgroundColor};
}
