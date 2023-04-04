/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NibblerWallComponent
*/

#include "NibblerCompType.hpp"
#include "NibblerWallComponent.hpp"

static const std::string defaultChar = "@";
static const Arcade::Graph::Color foregroundColor(0, 180, 40, 0);
static const Arcade::Graph::Color backgroundColor(0, 180, 50, 0);

Nibbler::Component::NibblerWallComponent::NibblerWallComponent(const std::string &id, const Arcade::Vector3f &pos)
    : Arcade::Graph::Sprite(id)
{
    this->type = Arcade::ECS::CompType::SPRITE;
    this->rect = Arcade::Graph::Rect(0, 0, 128, 128);
    this->path = "assets/snake/normal/box_02.png";
    this->currentRectIndex = 0;
    this->pos = pos;
    this->ttyData = {defaultChar, foregroundColor, backgroundColor};

}