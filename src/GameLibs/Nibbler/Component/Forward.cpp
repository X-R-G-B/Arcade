/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#include "Forward.hpp"
#include "NibblerCompType.hpp"

Nibbler::Component::Forward::Forward(const std::string &id, const Direction &direction):
    direction(direction)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::FORWARD;
}
