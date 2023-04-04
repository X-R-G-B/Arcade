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

Snake::Component::SnakeMapComponent::SnakeMapComponent(const std::string &id, const Arcade::Vector3f &pos)
    : Arcade::Graph::Sprite(id)
{
    this->type = Arcade::ECS::CompType::SNAKE_MAP;
    this->rect = Arcade::Graph::Rect(0, 0, 0, 0);
    this->path = "assets/snake/normal/bg_green_01.png";
    this->currentRectIndex = 0;
    this->pos = pos;
    this->ttyData = {defaultChar, foregroundColor, backgroundColor};
}
