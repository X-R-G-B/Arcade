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
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IComponent>>> musics;

    try {
        musics = entityManager.getComponentsByComponentType(Arcade::ECS::CompType::MUSIC);
    } catch (const std::exception &e) {
        return;
    }
    if (musics.get() == nullptr) {
        return;
    }
    for (const auto &comp : *musics) {
        const auto musicComp = std::static_pointer_cast<Arcade::Graph::Music>(comp);
        if (musicComp->play) {
            musicComp->play = false;
            _miniAudioWrapper.playSound(musicComp->path);
        }
    }
}
