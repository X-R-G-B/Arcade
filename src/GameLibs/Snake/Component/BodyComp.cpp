/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Body Comp
*/

#include "BodyComp.hpp"
#include "SnakeCompType.hpp"
#include "MagicValue.hpp"

Snake::Component::BodyComp::BodyComp()
{
    static int id = 0;
    this->id = SNAKE_BODY_COMP + std::to_string(++id);
    this->type = Arcade::ECS::CompType::BODYCOMP;
}
