/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Entity
*/

#include <algorithm>
#include <stdexcept>
#include "Entity.hpp"

Arcade::ECS::Entity::Entity(const std::string &id) : _id(id)
{
}

std::string Arcade::ECS::Entity::getId() const
{
    return this->_id;
}
