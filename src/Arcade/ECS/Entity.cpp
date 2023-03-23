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
    return this->_components;
}

const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &
Arcade::ECS::Entity::getComponents(Arcade::ECS::CompType type) const
{
    return this->_components.at(type);
}

static bool isAlreadyStored(
const std::map<Arcade::ECS::CompType,
std::vector<std::shared_ptr<Arcade::ECS::IComponent>>> &components,
const std::string &id)
{
    for (auto &component : components) {
        for (auto &comp : component.second) {
            if (comp->getId() == id)
                return true;
        }
    }
    return false;
}

void Arcade::ECS::Entity::addComponent(
std::shared_ptr<Arcade::ECS::IComponent> component)
{
    Arcade::ECS::CompType compType = component->getType();
    auto it = _components.find(compType);

    if (isAlreadyStored(_components, component->getId())) {
        throw std::runtime_error("Component already stored");
    }
    if (it == _components.end()) {
        _components[compType] =
        std::vector<std::shared_ptr<Arcade::ECS::IComponent>>();
        _components[compType].push_back(std::move(component));
    } else {
        it->second.push_back(std::move(component));
    }
}

void Arcade::ECS::Entity::removeComponent(const std::string &id)
{
    for (auto &component : this->_components) {
        std::remove_if(component.second.begin(), component.second.end(),
        [&id](const std::shared_ptr<Arcade::ECS::IComponent> &component) {
            return component->getId() == id;
        });
    }
}

void Arcade::ECS::Entity::removeComponents(Arcade::ECS::CompType type)
{
    this->_components.erase(type);
}
