/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGrow header
*/

#include "SnakeGrow.hpp"
#include "NibblerCompType.hpp"

Nibbler::Component::SnakeGrow::SnakeGrow(const std::string &id)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::SNAKEGROW;
    this->grow = 0;
    this->size = 0;
    this->lastIdBodyComp = "";
}
