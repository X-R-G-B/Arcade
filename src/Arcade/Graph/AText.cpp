/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AText
*/

#include "AText.hpp"

Arcade::Graph::AText::AText()
{
}

Arcade::Graph::AText::~AText()
{
}

const std::string &Arcade::Graph::AText::getId() const
{
       return (this->_Id);
}

const std::string &Arcade::Graph::AText::getFontPath() const
{
       return (this->_FontPath);
}

const std::string &Arcade::Graph::AText::getText() const
{
       return (this->_Text);
}

const Arcade::Graph::Color &Arcade::Graph::AText::getForegroundColor() const
{
       return (this->_ForegroundColor);
}

const Arcade::Graph::Color &Arcade::Graph::AText::getBackgroundColor() const
{
       return (this->_BackgroundColor);
}

const Arcade::Vector2f &Arcade::Graph::AText::getPos() const
{
       return (this->_Pos);
}

float Arcade::Graph::AText::getPoliceSize() const 
{
    return (this->_PoliceSize);
}

void Arcade::Graph::AText::setFontPath(const std::string &path) 
{
    this->_FontPath = path;
}

void Arcade::Graph::AText::setText(const std::string &text) 
{
    this->_Text = text;
}

void Arcade::Graph::AText::setBackgroundColor(Arcade::Graph::Color &color) 
{
    this->_BackgroundColor = color;
}

void Arcade::Graph::AText::setForegroundColor(Arcade::Graph::Color &color) 
{
    this->_ForegroundColor = color;
}

void Arcade::Graph::AText::setPoliceSize(float size) 
{
    this->_PoliceSize = size;
}

void Arcade::Graph::AText::setPos(Arcade::Vector2f &pos) 
{
    this->_Pos = pos;
}
