/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Music
*/

#include "Music.hpp"
#include "CompType.hpp"

Arcade::Graph::Music::Music(const std::string &id)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::MUSIC;
}
