/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#include "Moveable.hpp"
#include "SnakeCompType.hpp"

Snake::Component::Moveable::Moveable(const std::string &id, const Direction &direction)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::MOVEABLE;
    this->direction = direction;
}
