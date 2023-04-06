/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** Api to use main menu in different .so
*/

#pragma once

#include <string>
#include <vector>
#include "IEntityManager.hpp"
#include "IEventManager.hpp"
#include "IScene.hpp"

namespace Arcade {
    namespace MainMenu {
        /**
         * @brief The Context struct provided by the core
         */
        struct Context {
            std::vector<std::string> graphicalLibraries;
            std::vector<std::string> gameLibraries;
            std::string currentGraphicalLibrary;
            std::string currentGameLibrary;
        };

        /**
         * @brief The MainMenuModule interface
         *
         * This concret class will be created by the game .so and will be destroyed by the .so through
         * getMainMenuModule() method and destroyMainMenuModule() method
         */
        class IMainMenuModule {
            public:
                virtual ~IMainMenuModule() = default;

                /**
                 * @brief method that will be called each frame by the core
                 *
                 * You are expected to update the current scene in this method
                 *
                 * @param deltaTime time passed since last frame
                 * @param eventManager the event manager
                 */
                virtual void update(
                double deltaTime, Arcade::ECS::IEventManager &eventManager,
                Context *context) = 0;
                /**
                 * @brief Get the entity manager of the current active scene
                 *
                 * @return The entity manager of the current active scene
                 */
                virtual Arcade::ECS::IEntityManager &
                getCurrentEntityManager() = 0;
        };
    } // namespace MainMenu
} // namespace Arcade
