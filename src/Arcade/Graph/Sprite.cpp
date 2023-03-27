/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include "CompType.hpp"

Arcade::Graph::Sprite::Sprite(const std::string &id)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::SPRITE;
}
