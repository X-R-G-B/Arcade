/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_Music
*/

#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "IDisplayModule.hpp"
#include "SFML_Music.hpp"

static void playMusic(const std::string &path)
{
    sf::Music music;
    if (!music.openFromFile(path))
        return;
    music.play();
    while (music.getStatus() == sf::Music::Playing)
        sf::sleep(sf::seconds(0.1f));
}

static sf::Window &getSfWindow(Arcade::Core::IDisplayModule &displayModule)
{
    
}

void SFML_Music::run(std::size_t deltaTime, Arcade::ECS::IEventManager &,
Arcade::Core::IDisplayModule &displayModule,
Arcade::Core::IGameModule &gameModule)
{

}
