/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#include <curses.h>
#include <memory>
#include "NcursesCompType.hpp"
#include "Music.hpp"
#include "MUSIC.hpp"
#include "Ncurses.hpp"

void Ncurses::System::MusicSystem::run(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    auto texts = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::MUSIC);

    for (const auto &entity : *texts) {
        auto textComponents = entity->getComponents(Arcade::ECS::CompType::MUSIC);
        for (const auto &textComponent : textComponents) {
            const auto text = std::static_pointer_cast<Arcade::Graph::Music>(textComponent);
            if (text->play) {
                text->play = false;
                _miniAudioWrapper.playSound(text->path);
            }
        }
    }
}
