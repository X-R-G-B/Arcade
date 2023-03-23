/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Music
*/

#include "Music.hpp"

Arcade::Graph::Music::Music(const std::string &id)
    : AComponent(Arcade::ECS::CompType::MUSIC, id), _Path(""), _Loop(false), _IsPlaying(false), _Volume(0)
{
}

Arcade::Graph::Music::~Music()
{
}

const std::string &Arcade::Graph::Music::getPath() const
{
    return (this->_Path);
}

bool Arcade::Graph::Music::getLoop() const
{
    return (this->_Loop);
}

bool Arcade::Graph::Music::getIsPlaying() const
{
    return (this->_IsPlaying);
}

float Arcade::Graph::Music::getVolume() const
{
    return (this->_Volume);
}

void Arcade::Graph::Music::setPath(const std::string &path)
{
    _Path = path;    
}

void Arcade::Graph::Music::setLoop(bool loop)
{
    _Loop = loop;
}

void Arcade::Graph::Music::setIsPlaying(bool isPlaying)
{
    _IsPlaying = isPlaying;
}

void Arcade::Graph::Music::setVolume(float volume)
{
    _Volume = volume;    
}

