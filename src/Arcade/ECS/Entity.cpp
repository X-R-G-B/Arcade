/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Entity
*/

#include <algorithm>
#include <stdexcept>
#include "Entity.hpp"
#include "Exceptions.hpp"

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
    auto it = this->_components.find(type);

    if (it == this->_components.end()) {
        throw ArcadeExceptions("Components of type : " + std::to_string(static_cast<int>(type)) + " not founds");
    }
    return it->second;
}

Arcade::ECS::IComponent &Arcade::ECS::Entity::getComponents(const std::string &id)
{ 
    for (auto &component : _components) {
        for (auto &comp : component.second) {
            if (comp->id == id)
                return *(comp.get());
        }
    }
    throw ArcadeExceptions("Invalid argument => getComponents(id) : Unknown id : " + id);
}

bool Arcade::ECS::Entity::isAlreadyStored(const std::string &id)
{
    for (auto &component : _components) {
        for (auto &comp : component.second) {
            if (comp->id == id)
                return true;
        }
    }
    return false;
}

void Arcade::ECS::Entity::addComponent(
std::shared_ptr<Arcade::ECS::IComponent> component)
{
    Arcade::ECS::CompType compType = component->type;
    auto it = _components.find(compType);

    if (isAlreadyStored(component->id)) {
        throw ArcadeExceptions("Component already stored");
    } else if (it == _components.end()) {
        _components[compType] =
        std::vector<std::shared_ptr<Arcade::ECS::IComponent>>();
        _components[compType].push_back(std::move(component));
    } else {
        it->second.push_back(std::move(component));
    }
}

#include <iostream>
void Arcade::ECS::Entity::removeComponent(const std::string &id)
{
    for (auto &component : this->_components) {
        auto _ = std::remove_if(component.second.begin(), component.second.end(),
        [&id](const std::shared_ptr<Arcade::ECS::IComponent> &component) {
            if (component.get() == nullptr) {
                return false;
            }
            return component->id == id;
        });
    }
}

void Arcade::ECS::Entity::removeComponent(Arcade::ECS::CompType type)
{
    this->_components.erase(type);
}
