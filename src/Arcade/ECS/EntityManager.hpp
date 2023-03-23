/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** Manager for entity that add some usefull abstraction
*/

#pragma once

#include <memory>
#include <string>
#include "IEntityManager.hpp"

namespace Arcade {
    namespace ECS {
        /**
         * @brief Manage the creation of entities and their access
         */
        class EntityManager : public IEntityManager {
            public:
                EntityManager() = default;
                ~EntityManager() = default;
                /**
                 * @brief Add an entity to the manager
                 *
                 * @param id The id of the entity
                 *
                 * @return The entity created
                 */
                IEntity &createEntity(const std::string &id) override;
                /**
                 * @brief Get all entities created by this manager
                 *
                 * @return A vector of all entities created by this manager
                 */
                const std::vector<std::shared_ptr<IEntity>> &
                getEntities() const override;
                /**
                 * @brief Get all entities created by this manager that have at
                 * least one component of type CompType
                 *
                 * @param comp The component type to check in each entity
                 *
                 * @return The vector
                 */
                std::unique_ptr<std::vector<std::shared_ptr<IEntity>>>
                getEntitiesByComponentType(CompType comp) const override;
                /**
                 * @brief Remove an entity from the manager
                 *
                 * @param id The entity id to remove
                 */
                void removeEntity(const std::string &id) override;
                /**
                 * @brief Remove all entities from the manager
                 */
                void removeAllEntities() override;

            private:
                std::vector<std::shared_ptr<IEntity>> _entities;
        };
    } // namespace ECS
} // namespace Arcade
