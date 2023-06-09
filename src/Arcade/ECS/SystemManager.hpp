/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** System manager class
*/

#pragma once

#include <memory>
#include <string>
#include <vector>
#include "IEntityManager.hpp"
#include "IEventManager.hpp"
#include "ISystem.hpp"
#include "ISystemManager.hpp"

namespace Arcade {
    namespace ECS {
        class SystemManager : ISystemManager {
            public:
                SystemManager() = default;
                ~SystemManager() = default;
                /**
                 * @brief Add a system to the system manager
                 *
                 * @param name The name of the system
                 * @param system The system to add
                 */
                void addSystem(const std::string &name,
                std::unique_ptr<Arcade::ECS::ISystem> system) final;
                /**
                 * @brief Remove a system from the system manager
                 *
                 * @param name The name of the system to remove
                 */
                void removeSystem(const std::string &name) final;
                /**
                 * @brief Update all systems of the system manager
                 *
                 * @param deltaTime The time since the last update
                 * @param entityManager The list of entities
                 * @param eventManager The list of events
                 */
                void update(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) final;
            private:
                std::map<std::string, std::unique_ptr<Arcade::ECS::ISystem>> _systems;
        };
    } // namespace ECS
} // namespace Arcade
