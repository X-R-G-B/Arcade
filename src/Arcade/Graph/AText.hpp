/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AText
*/

#pragma once

#include "IText.hpp"

namespace Arcade {
    namespace Graph {
        class AText : public IText {
            public:
                AText();
                ~AText();

                const std::string &getId() const;
                const std::string &getFontPath() const;
                const std::string &getText() const;
                const Arcade::Graph::Color &getForegroundColor() const;
                const Arcade::Graph::Color &getBackgroundColor() const;
                const Arcade::Vector2f &getPos() const;
                float getPoliceSize() const;


                void setFontPath(const std::string &path);
                void setText(const std::string &text);
                void setBackgroundColor(Arcade::Graph::Color &color);
                void setForegroundColor(Arcade::Graph::Color &color);
                void setPoliceSize(float size);
                void setPos(Arcade::Vector2f &pos);

            protected:
            private:
                std::string _Id;
                std::string _FontPath;
                std::string _Text;
                float _PoliceSize;
                Arcade::Graph::Color _ForegroundColor;
                Arcade::Graph::Color _BackgroundColor;
                Arcade::Vector2f _Pos;
        };
    }
}
