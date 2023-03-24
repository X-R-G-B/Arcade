/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Component Manager header
*/

#pragma once

#include <map>
#include <optional>
#include <vector>
#include <memory>
#include "IComponent.hpp"

namespace Arcade {
    namespace ECS {
        class ComponentManager {
            protected:
                /**
                 * @brief Get all components
                 *
                 * @return The list of components
                 */
                const std::map<CompType,
                std::vector<std::shared_ptr<IComponent>>> &
                getComponents() const;
                /**
                 * @brief Get all components of type `compType`
                 *
                 * @param type The type of component to get
                 *
                 * @return The list of components filtered
                 */
                const std::vector<std::shared_ptr<IComponent>> &getComponents(
                CompType type) const;
                /**
                 * @brief Get the component of the current active graphical
                 * library
                 *
                 * @param componentId The component id to get
                 *
                 * @return optional of the component id if found
                 */
                virtual std::optional<std::shared_ptr<ECS::IComponent>>
                getComponent(const std::string &componentId) const;
                /**
                 * @brief Add a component
                 *
                 * @param component The component to add
                 */
                void addComponent(
                std::shared_ptr<IComponent> component);
                /**
                 * @brief Remove a component
                 *
                 * @param std::string The component id to remove
                 */
                void removeComponent(const std::string &id);
                /**
                 * @brief Remove all components of type `CompType`
                 *
                 * @param type The type of component to remove
                 */
                void removeComponents(CompType type);
            private:
                std::map<CompType, std::vector<std::shared_ptr<IComponent>>>
                _components;
                bool isAlreadyStored(const std::string &id);
        };
    }
}