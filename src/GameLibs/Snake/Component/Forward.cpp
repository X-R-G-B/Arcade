/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#include "Forward.hpp"
#include "SnakeCompType.hpp"

Snake::Component::Forward::Forward(const std::string &id, const Direction &direction):
    direction(direction)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::FORWARD;
}
