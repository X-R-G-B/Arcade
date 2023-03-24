/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** Entity is the most little thing in the ECS (you can add component to it)
*/

#pragma once

#include "IEntity.hpp"
#include "ComponentManager.hpp"

namespace Arcade {
    namespace ECS {
        /**
         * @brief The Entity interface
         */
        class Entity : public IEntity, public ComponentManager {
            public:
                Entity(const std::string &id);
                virtual ~Entity() = default;
                /**
                 * @brief Get the entity id
                 *
                 * @return The entity id
                 */
                std::string getId() const final;

            private:
                std::string _id;
        };
    } // namespace ECS
} // namespace Arcade
