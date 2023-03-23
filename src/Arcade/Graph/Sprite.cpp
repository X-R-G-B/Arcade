/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sprite
*/

#include "Sprite.hpp"

Arcade::Graph::Sprite::Sprite(std::string &id)
    : AComponent(Arcade::ECS::CompType::SPRITE, id), _Scale(0)
{
}

Arcade::Graph::Sprite::~Sprite()
{
}

const std::string &Arcade::Graph::Sprite::getPath() const
{
    return (this->_Path);
}

const Arcade::Graph::TTYData &Arcade::Graph::Sprite::getTTYData() const
{
    return (this->_TTYData);
}

const Arcade::Vector3f &Arcade::Graph::Sprite::getPos() const
{
    return (this->_Pos);
}

const Arcade::Vector3f &Arcade::Graph::Sprite::getSize() const
{
    return (this->_Size);
}

const Arcade::Graph::Color &Arcade::Graph::Sprite::getColor() const
{
    return (this->_Color);
}

const Arcade::Graph::Rect &Arcade::Graph::Sprite::getRect() const
{
    return (this->_Rect);
}

float Arcade::Graph::Sprite::getScale() const
{
    return (this->_Scale);
}

void Arcade::Graph::Sprite::setPath(const std::string &path)
{
    this->_Path = path;
}

void Arcade::Graph::Sprite::setTTYData(const TTYData &ttydata)
{
    this->_TTYData = ttydata;
}

void Arcade::Graph::Sprite::setPos(const Arcade::Vector3f &pos)
{
    this->_Pos = pos;
}

void Arcade::Graph::Sprite::setSize(const Arcade::Vector3f &size)
{
    this->_Size = size;
}

void Arcade::Graph::Sprite::setRect(const Rect &rect)
{
    this->_Rect = rect;
}

void Arcade::Graph::Sprite::setColor(const Color &color)
{
    this->_Color = color;
}

void Arcade::Graph::Sprite::setScale(float scale)
{
    this->_Scale = scale;
}
