/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AMusic
*/

#pragma once

#include "IMusic.hpp"
#include "AComponent.hpp"

namespace Arcade {
    namespace Graph {
        class AMusic : public IMusic, public Arcade::ECS::AComponent {
            public:
                AMusic();
                ~AMusic();

                const std::string &getPath() const final;
                bool getLoop() const final;
                bool getIsPlaying() const final;
                float getVolume() const final;

                void setVolume(float volume) final;
                void setIsPlaying(bool isPlaying) final;
                void setLoop(bool loop) final;
                void setPath(const std::string &path) final;


            protected:
            private:
                std::string _Id;
                std::string _Path;
                bool _Loop;
                bool _IsPlaying;
                float _Volume;
        };
    }
}

