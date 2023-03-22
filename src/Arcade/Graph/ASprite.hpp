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
                const std::string &getPath() const;
                const TTYData &getTTYData() const;
                const Arcade::Vector3f &getPos() const;
                const Arcade::Vector3f &getSize() const;
                const Color &getColor() const;
                const Rect &getRect() const;
                const float getScale() const;


                void setPath(const std::string &path);
                void setTTYData(const TTYData &ttydata);
                void setPos(Vector3f &pos);
                void setSize(Vector3f &size);
                void setRect(Rect &rect);
                void setColor(Color &color);
                void setScale(float scale);
            protected:
            private:
                std::string _Path;
                TTYData _TTYData;
                Vector3f _Pos;
                Vector3f _Size;
                Rect _Rect;
                Color _Color;
                float _Scale;
        };
    }
}