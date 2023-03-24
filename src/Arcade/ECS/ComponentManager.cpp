/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Component Manager
*/

#include "ComponentManager.hpp"

const std::map<Arcade::ECS::CompType,
std::vector<std::shared_ptr<Arcade::ECS::IComponent>>> &
Arcade::ECS::ComponentManager::getComponents() const
{
    return this->_components;
}

const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &
Arcade::ECS::ComponentManager::getComponents(Arcade::ECS::CompType type) const
{
    auto it = this->_components.find(type);

    if (it == this->_components.end()) {
        throw std::runtime_error("Component not found");
    }
    return it->second;
}

std::optional<std::shared_ptr<Arcade::ECS::IComponent>>
Arcade::ECS::ComponentManager::getComponent(const std::string &componentId) const
{
    for (auto &component : _components) {
        for (auto &comp : component.second) {
            if (comp->getId() == componentId) {
                return comp;
            }
        }
    }
    return std::nullopt;
}

bool Arcade::ECS::ComponentManager::isAlreadyStored(const std::string &id)
{
    for (auto &component : _components) {
        for (auto &comp : component.second) {
            if (comp->getId() == id) {
                return true;
            }
        }
    }
    return false;
}

void Arcade::ECS::ComponentManager::addComponent(
std::shared_ptr<Arcade::ECS::IComponent> component)
{
    Arcade::ECS::CompType compType = component->getType();
    auto it = _components.find(compType);

    if (isAlreadyStored(component->getId())) {
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

void Arcade::ECS::ComponentManager::removeComponent(const std::string &id)
{
    for (auto &component : this->_components) {
        std::remove_if(component.second.begin(), component.second.end(),
        [&id](const std::shared_ptr<Arcade::ECS::IComponent> &component) {
            return component->getId() == id;
        });
    }
}

void Arcade::ECS::ComponentManager::removeComponents(Arcade::ECS::CompType type)
{
    this->_components.erase(type);
}
