/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** Entity is the most little thing in the ECS (you can add component to it)
*/

#pragma once

#include "IEntity.hpp"

namespace Arcade {
    namespace ECS {
        /**
         * @brief The Entity interface
         */
        class Entity : public Arcade::ECS::IEntity {
            public:
                Entity(const std::string &id);
                ~Entity() = default;
                /**
                 * @brief Get the entity id
                 *
                 * @return The entity id
                 */
                std::string getId() const final;
                /**
                 * @brief Get all components
                 *
                 * @return The list of components
                 */
                const std::map<CompType,
                std::vector<std::shared_ptr<IComponent>>> &
                getComponents() const final;
                /**
                 * @brief Get all components of type `compType`
                 *
                 * @param type The type of component to get
                 *
                 * @return The list of components filtered
                 */
                const std::vector<std::shared_ptr<IComponent>> &getComponents(
                CompType type) const final;
                /**
                 * @brief Get component by its id
                 *
                 * @param id The id of the component to get
                 *
                 * @return The component (if it doesn't exists: throw)
                 */
                IComponent &getComponents(const std::string &id) final;
                /**
                 * @brief Add a component
                 *
                 * @param component The component to add
                 */
                void addComponent(
                std::shared_ptr<IComponent> component) final;
                /**
                 * @brief Remove a component
                 *
                 * @param std::string The component id to remove
                 */
                void removeComponent(const std::string &id) final;
                /**
                 * @brief Remove all components of type `CompType`
                 *
                 * @param type The type of component to remove
                 */
                void removeComponent(CompType type) final;

            private:
                std::string _id;
                std::map<CompType, std::vector<std::shared_ptr<IComponent>>>
                _components;
                bool isAlreadyStored(const std::string &id);
        };
    } // namespace ECS
} // namespace Arcade
