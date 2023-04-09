/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NibblerWallComponent
*/

#include "MagicValue.hpp"
#include "NibblerCompType.hpp"
#include "NibblerWallComponent.hpp"

static const Arcade::Graph::Color foregroundColor(255, 255, 100, 0);
static const Arcade::Graph::Color backgroundColor(255, 255, 100, 0);

#define WALL_PATH "assets/snake/normal/box_02.png"
#define DEFAULT_CHAR "#####\n#####\n#####"

Nibbler::Component::NibblerWallComponent::NibblerWallComponent(const std::string &id, const Arcade::Vector3f &pos)
    : Arcade::Graph::Sprite(id)
{
    this->type = Arcade::ECS::CompType::SPRITE;
    this->rect = Arcade::Graph::Rect(0, 0, PARCELL_SIZE, PARCELL_SIZE);
    this->path = WALL_PATH;
    this->currentRectIndex = 0;
    this->pos = pos;
    this->ttyData = {DEFAULT_CHAR, foregroundColor, backgroundColor};
}
