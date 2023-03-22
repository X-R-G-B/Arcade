/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** Components that will be added to entity
*/

#pragma once

#include "IComponent.hpp"

namespace Arcade {
    namespace ECS {
        /**
         * @brief The AComponents interface
         *
         * defaultComponent type to implement: TEXT, SPRITE, MUSIC
         */
        enum class CompType {
            TEXT = 0,
            SPRITE = 1,
            MUSIC = 2,
        };

        class AComponent: public Arcade::ECS::IComponent {
            public:
                AComponent(CompType type, const std::string &id);
                virtual ~AComponent() = default;

                /**
                 * @brief Get the type of the component.
                 *
                 * @return The component type (CompType)
                 */
                CompType getType();
                /**
                 * @brief Get the id of the component.
                 *
                 * @return The component id
                 */
                const std::string &getId();
            private:
                CompType _type;
                std::string _id;
        };
    } // namespace ECS
};    // namespace Arcade
