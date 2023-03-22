/*
** EPITECH PROJECT, 2023
** archi_arcade
** File description:
** AComponent
*/

#include "AComponent.hpp"

Arcade::ECS::AComponent::AComponent(Arcade::ECS::CompType type, const std::string &id)
    : _type(type), _id(id)
{
}

Arcade::ECS::CompType Arcade::ECS::AComponent::getType()
{
    return _type;
}

const std::string &Arcade::ECS::AComponent::getId()
{
    return _id;
}
