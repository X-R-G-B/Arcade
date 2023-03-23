/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#include "Text.hpp"

Arcade::Graph::Text::Text(const std::string &id)
    : AComponent(Arcade::ECS::CompType::TEXT, id), _FontPath(""), _Text(""), _PoliceSize(0)
{
}

Arcade::Graph::Text::~Text()
{
}

const std::string &Arcade::Graph::Text::getId() const
{
    return (this->_Id);
}

const std::string &Arcade::Graph::Text::getFontPath() const
{
    return (this->_FontPath);
}

const std::string &Arcade::Graph::Text::getText() const
{
    return (this->_Text);
}

const Arcade::Graph::Color &Arcade::Graph::Text::getForegroundColor() const
{
    return (this->_ForegroundColor);
}

const Arcade::Graph::Color &Arcade::Graph::Text::getBackgroundColor() const
{
   return (this->_BackgroundColor);
}

const Arcade::Vector2f &Arcade::Graph::Text::getPos() const
{
    return (this->_Pos);
}

float Arcade::Graph::Text::getPoliceSize() const 
{
    return (this->_PoliceSize);
}

void Arcade::Graph::Text::setFontPath(const std::string &path) 
{
    this->_FontPath = path;
}

void Arcade::Graph::Text::setText(const std::string &text) 
{
    this->_Text = text;
}

void Arcade::Graph::Text::setBackgroundColor(const Arcade::Graph::Color &color) 
{
    this->_BackgroundColor = color;
}

void Arcade::Graph::Text::setForegroundColor(const Arcade::Graph::Color &color) 
{
    this->_ForegroundColor = color;
}

void Arcade::Graph::Text::setPoliceSize(float size) 
{
    this->_PoliceSize = size;
}

void Arcade::Graph::Text::setPos(const Arcade::Vector2f &pos) 
{
    this->_Pos = pos;
}
