/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ASprite
*/

#include "ASprite.hpp"

Arcade::Graph::ASprite::ASprite(std::string &id)
{
}

Arcade::Graph::ASprite::~ASprite()
{
}

const std::string &Arcade::Graph::ASprite::getPath() const
{
    return (this->_Path);
}

const Arcade::Graph::TTYData &Arcade::Graph::ASprite::getTTYData() const
{
    return (this->_TTYData);
}

const Arcade::Vector3f &Arcade::Graph::ASprite::getPos() const
{
    return (this->_Pos);
}

const Arcade::Vector3f &Arcade::Graph::ASprite::getSize() const
{
    return (this->_Size);
}

const Arcade::Graph::Color &Arcade::Graph::ASprite::getColor() const
{
    return (this->_Color);
}

const Arcade::Graph::Rect &Arcade::Graph::ASprite::getRect() const
{
    return (this->_Rect);
}

const float Arcade::Graph::ASprite::getScale() const
{
    return (this->_Scale);
}

void Arcade::Graph::ASprite::setPath(const std::string &path)
{
    this->_Path = path;
}

void Arcade::Graph::ASprite::setTTYData(const TTYData &ttydata)
{
    this->_TTYData = ttydata;
}

void Arcade::Graph::ASprite::setPos(Arcade::Vector3f &pos)
{
    this->_Pos = pos;
}

void Arcade::Graph::ASprite::setSize(Arcade::Vector3f &size)
{
    this->_Size = size;
}

void Arcade::Graph::ASprite::setRect(Rect &rect)
{
    this->_Rect = rect;
}

void Arcade::Graph::ASprite::setColor(Color &color)
{
    this->_Color = color;
}

void Arcade::Graph::ASprite::setScale(float scale)
{
    this->_Scale = scale;
}
