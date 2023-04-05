/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NibblerWallComponentId
*/

#include "NibblerCompType.hpp"
#include "NibblerWallComponentId.hpp"

Nibbler::Component::NibblerWallComponentId::NibblerWallComponentId(const std::string &id)
{
    this->type = Arcade::ECS::CompType::WALL;
    this->id = id;
}