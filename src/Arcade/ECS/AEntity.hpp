/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** Entity is the most little thing in the ECS (you can add component to it)
*/

#pragma once

#include <cstddef>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "IComponent.hpp"

namespace Arcade {
    namespace ECS {
        /**
         * @brief The AEntity interface
         */
        class AEntity {
            public:
                AEntity(const std::string &id);
                virtual ~AEntity() = default;
                /**
                 * @brief Get the entity id
                 *
                 * @return The entity id
                 */
                std::string getId() const;
                /**
                 * @brief Get all components
                 *
                 * @return The list of components
                 */
                const std::map<CompType,
                std::vector<std::unique_ptr<IComponent>>> &
                getComponents();
                /**
                 * @brief Get all components of type `compType`
                 *
                 * @param type The type of component to get
                 *
                 * @return The list of components filtered
                 */
                const std::vector<std::unique_ptr<IComponent>> &getComponents(
                CompType type);
                /**
                 * @brief Add a component
                 *
                 * @param component The component to add
                 */
                void addComponent(std::unique_ptr<IComponent> component);
                /**
                 * @brief Remove a component
                 *
                 * @param std::string The component id to remove
                 */
                void removeComponent(std::string &id);
                /**
                 * @brief Remove all components of type `CompType`
                 *
                 * @param type The type of component to remove
                 */
                void removeComponents(CompType type);

            private:
                std::string _id;
                std::map<CompType, std::vector<std::unique_ptr<IComponent>>>
                _components = {};
        };
    } // namespace ECS
} // namespace Arcade
