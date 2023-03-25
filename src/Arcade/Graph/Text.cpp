/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#include "Text.hpp"

Arcade::Graph::Text::Text(std::string textId)
{
    this->id = textId;
    this->type = Arcade::ECS::CompType::TEXT;
}
