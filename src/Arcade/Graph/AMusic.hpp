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

                const std::string &getId() const;
                const std::string &getPath() const;
                bool getLoop() const;
                bool getIsPlaying() const;
                float getVolume() const;
                virtual void setVolume(float volume) = 0;
                virtual void setIsPlaying(bool isPlaying) = 0;
                virtual void setLoop(bool loop) = 0;
                virtual void setPath(const std::string &path) = 0;


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

