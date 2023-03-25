/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** System manager class
*/

#include <algorithm>
#include <memory>
#include "SystemManager.hpp"

namespace Arcade {
    namespace ECS {
        void SystemManager::addSystem(const std::string &name, std::unique_ptr<Arcade::ECS::ISystem> system)
        {
            auto it = _systems.find(name);
            if (it != _systems.end()) {
                throw std::invalid_argument("System already exists");
            }
            _systems[name].swap(system);
        }

        void SystemManager::removeSystem(const std::string &name)
        {
            auto it = _systems.find(name);
            if (it == _systems.end()) {
                throw std::invalid_argument("System does not exist");
            }
            _systems.erase(it);
        }

        void SystemManager::update(float deltaTime,
            Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentScene)
        {
            for (auto &system : _systems) {
                system.second->run(deltaTime, eventManager, currentScene);
            }
        }
    }
}
