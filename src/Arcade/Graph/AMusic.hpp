/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AMusic
*/

#pragma once

#include "IMusic.hpp"

namespace Arcade {
    namespace Graph {
        class AMusic : public IMusic {
            public:
                AMusic();
                ~AMusic();

                const std::string &getPath() const override;
                bool getLoop() const override;
                bool getIsPlaying() const override;
                float getVolume() const override;

                void setVolume(float volume) override;
                void setIsPlaying(bool isPlaying) override;
                void setLoop(bool loop) override;
                void setPath(const std::string &path) override;


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

