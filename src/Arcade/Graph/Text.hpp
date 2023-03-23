/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#pragma once

#include "IText.hpp"
#include "AComponent.hpp"

namespace Arcade {
    namespace Graph {
        class Text : public IText, public Arcade::ECS::AComponent {
            public:
                Text(const std::string &id);
                ~Text();

                const std::string &getFontPath() const final;
                const std::string &getText() const final;
                const Arcade::Graph::Color &getForegroundColor() const final;
                const Arcade::Graph::Color &getBackgroundColor() const final;
                const Arcade::Vector2f &getPos() const final;
                float getPoliceSize() const final;


                void setFontPath(const std::string &path) final;
                void setText(const std::string &text) final;
                void setBackgroundColor(const Arcade::Graph::Color &color) final;
                void setForegroundColor(const Arcade::Graph::Color &color) final;
                void setPoliceSize(float size) final;
                void setPos(const Arcade::Vector2f &pos) final;

            protected:
            private:
                std::string _Id;
                std::string _FontPath;
                std::string _Text;
                float _PoliceSize;
                Color _ForegroundColor;
                Color _BackgroundColor;
                Arcade::Vector2f _Pos;
        };
    }
}
