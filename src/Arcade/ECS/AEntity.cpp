/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AEntity
*/

#include <algorithm>
#include "AEntity.hpp"

Arcade::ECS::AEntity::AEntity(const std::string &id) : _id(id), _components({})
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
    Arcade::ECS::CompType compType = component->getType();
    auto it = _components.find(compType);

    if (it == _components.end()) {
        _components[compType] = {std::move(component)};
    } else {
        it->second.push_back(component);
    }
}

void Arcade::ECS::AEntity::removeComponent(const std::string &id)
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
