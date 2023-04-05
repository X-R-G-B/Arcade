/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NibblerMapComponent
*/

#include "MagicValue.hpp"
#include "NibblerCompType.hpp"
#include "NibblerMapComponent.hpp"

static const Arcade::Graph::Color foregroundColor(0, 180, 0, 0);
static const Arcade::Graph::Color backgroundColor(0, 180, 0, 0);

#define DARK_PARCELL "assets/snake/normal/bg_green_01.png"
#define LIGHT_PARCELL "assets/snake/normal/bg_green_02.png"
#define DEFAULT_CHAR "~"

Nibbler::Component::NibblerMapComponent::NibblerMapComponent(const std::string &id, const Arcade::Vector3f &pos, const bool darkColor)
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
