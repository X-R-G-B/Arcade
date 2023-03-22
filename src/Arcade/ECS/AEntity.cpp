/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AEntity
*/

#include <algorithm>
#include "AEntity.hpp"

Arcade::ECS::AEntity::AEntity(const std::string &id) : _id(id)
{
}

std::string Arcade::ECS::AEntity::getId() const
{
    return this->_id;
}

const std::map<Arcade::ECS::CompType,
std::vector<std::unique_ptr<Arcade::ECS::IComponent>>> &
Arcade::ECS::AEntity::getComponents()
{
    return this->_components;
}

const std::vector<std::unique_ptr<Arcade::ECS::IComponent>> &
Arcade::ECS::AEntity::getComponents(Arcade::ECS::CompType type)
{
    return this->_components[type];
}

void Arcade::ECS::AEntity::addComponent(
std::unique_ptr<Arcade::ECS::IComponent> component)
{
    if (this->_components.find(component->getType())
    == this->_components.end()) {
        this->_components.insert(
        {component->getType(), {std::move(component)}});
    } else {
        this->_components[component->getType()].push_back(std::move(component));
    }
}

void Arcade::ECS::AEntity::removeComponent(std::string &id)
{
    for (auto &component : this->_components) {
        std::remove_if(component.second.begin(), component.second.end(),
        [&id](const std::unique_ptr<Arcade::ECS::IComponent> &component) {
            return component->getId() == id;
        });
    }
}

void Arcade::ECS::AEntity::removeComponents(Arcade::ECS::CompType type)
{
    this->_components.erase(type);
}
