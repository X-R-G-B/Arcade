/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AMusic
*/

#include "AMusic.hpp"

Arcade::Graph::AMusic::AMusic()
{
}

Arcade::Graph::AMusic::~AMusic()
{
}

const std::string &Arcade::Graph::AMusic::getId() const
{
    return (this->_Id);
}

const std::string &Arcade::Graph::AMusic::getPath() const
{
    return (this->_Path);
}

bool Arcade::Graph::AMusic::getLoop() const
{
    return (this->_Loop);
}

bool Arcade::Graph::AMusic::getIsPlaying() const
{
    return (this->_IsPlaying);
}

float Arcade::Graph::AMusic::getVolume() const
{
    return (this->_Volume);
}

void Arcade::Graph::AMusic::setPath(const std::string &path)
{
    _Path = path;    
}

void Arcade::Graph::AMusic::setLoop(bool loop)
{
    _Loop = loop;
}

void Arcade::Graph::AMusic::setIsPlaying(bool isPlaying)
{
    _IsPlaying = isPlaying;
}

void Arcade::Graph::AMusic::setVolume(float volume)
{
    _Volume = volume;    
}

