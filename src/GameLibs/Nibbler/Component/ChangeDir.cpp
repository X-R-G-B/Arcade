/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#include "ChangeDir.hpp"
#include "NibblerCompType.hpp"

Nibbler::Component::ChangeDir::ChangeDir(const std::string &id, const Direction &direction, const Arcade::Vector2f &pos):
    direction(direction), pos(pos)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::CHANGEDIR;
}
