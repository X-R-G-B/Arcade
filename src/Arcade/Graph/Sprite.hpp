/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ASprite
*/

#pragma once

#include "ISprite.hpp"
#include "AComponent.hpp"

namespace Arcade {
    namespace Graph {
        class Sprite : public ISprite, public Arcade::ECS::AComponent {
            public:
                Sprite(std::string &id);
                ~Sprite();
                const std::string &getPath() const final;
                const TTYData &getTTYData() const final;
                const Arcade::Vector3f &getPos() const final;
                const Arcade::Vector3f &getSize() const final;
                const Color &getColor() const final;
                const Rect &getRect() const final;
                float getScale() const final;

                void setPath(const std::string &path) final;
                void setTTYData(const TTYData &ttydata) final;
                void setPos(const Vector3f &pos) final;
                void setSize(const Vector3f &size) final;
                void setRect(const Rect &rect) final;
                void setColor(const Color &color) final;
                void setScale(float scale) final;
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