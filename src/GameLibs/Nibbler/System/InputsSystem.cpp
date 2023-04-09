/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#include "InputsSystem.hpp"
#include "MagicValue.hpp"

void Nibbler::System::InputsSystem::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    if (eventManager.isEventTriggered("KEY_ESC_PRESSED").first) {
        eventManager.addEvent("GAME_END");
    } else if (eventManager.isEventTriggered("KEY_1_PRESSED").first) {
        eventManager.addEvent("CHANGE_GAME");
    } else if (eventManager.isEventTriggered("KEY_2_PRESSED").first) {
        eventManager.addEvent("CHANGE_GRAPH");
    }
}
