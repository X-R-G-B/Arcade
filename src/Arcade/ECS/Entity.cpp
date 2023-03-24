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

const std::map<Arcade::ECS::CompType,
std::vector<std::shared_ptr<Arcade::ECS::IComponent>>> &
Arcade::ECS::Entity::getComponents() const
{
    return ComponentManager::getComponents();
}

const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &
Arcade::ECS::Entity::getComponents(Arcade::ECS::CompType type) const
{
    return ComponentManager::getComponents(type);
}

void Arcade::ECS::Entity::addComponent(
std::shared_ptr<Arcade::ECS::IComponent> component)
{
    ComponentManager::addComponent(component);
}

void Arcade::ECS::Entity::removeComponent(const std::string &id)
{
    ComponentManager::removeComponent(id);
}

void Arcade::ECS::Entity::removeComponents(Arcade::ECS::CompType type)
{
    ComponentManager::removeComponents(type);
}
