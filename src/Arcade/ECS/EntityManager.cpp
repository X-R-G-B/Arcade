/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** Manager for entity that add some usefull abstraction
*/

#include "ECSException.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"

Arcade::ECS::IEntity &Arcade::ECS::EntityManager::createEntity(
const std::string &id)
{
    std::shared_ptr<Arcade::ECS::Entity> entity = nullptr;

    if (id.empty())
        throw Arcade::ECS::ECSException("Entity id can't be empty");
    for (auto &entity : _entities) {
        if (entity->getId() == id) {
            throw Arcade::ECS::ECSException("Entity id already exist");
        }
    }
    entity = std::make_shared<Arcade::ECS::Entity>(id);
    _entities.push_back(entity);
    return *entity;
}

const std::vector<std::shared_ptr<Arcade::ECS::IEntity>> &
Arcade::ECS::EntityManager::getEntities() const
{
    return _entities;
}

std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>>
Arcade::ECS::EntityManager::getEntitiesByComponentType(
Arcade::ECS::CompType comp) const
{
    auto entities =
    std::make_unique<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>>();

    for (auto &entity : this->_entities) {
        if (entity->getComponents().find(comp) != entity->getComponents().end())
            entities->push_back(entity);
    }
    return entities;
}

void Arcade::ECS::EntityManager::removeEntity(const std::string &id)
{
    for (auto it = _entities.begin(); it != _entities.end(); ++it) {
        if ((*it)->getId() == id) {
            _entities.erase(it);
            return;
        }
    }
}

void Arcade::ECS::EntityManager::removeAllEntities()
{
    _entities.clear();
}
