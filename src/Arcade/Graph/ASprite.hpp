/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ASprite
*/

#pragma once

#include "ISprite.hpp"

namespace Arcade {
    namespace Graph {
        class ASprite {
            public:
                ASprite(std::string &id);
                ~ASprite();
                const std::string &getId() const;
                const std::string &getPath() const;
                const TTYData &getTTYData() const;
                const Arcade::Vector3f &getPos() const;
                const Arcade::Vector3f &getSize() const;
                const Color &getColor() const;
                const Rect getRect() const;
                const float getScale() const;


                void setPath(const std::string &text);
                void setTTYData(const TTYData &ttydata);
                void setPos(Arcade::Vector3f &pos);
                void setSize(Arcade::Vector3f &size);
                void setRect(Rect &rect);
                void setColor(Color &color);
                void setScale(float scale);
            protected:
            private:
                std::string _Id;
                std::string _Path;
        };
    }
}