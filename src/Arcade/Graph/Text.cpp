/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#include "Text.hpp"

Arcade::Graph::Text::Text(const std::string &id)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::TEXT;
}
