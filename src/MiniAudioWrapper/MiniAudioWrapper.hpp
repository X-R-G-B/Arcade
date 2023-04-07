/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MiniAudioWrapper
*/

#pragma once

#include <string>
#include "miniaudio.h"

namespace MiniAudio {
    class MiniAudioWrapper {
        public:
            MiniAudioWrapper();
            ~MiniAudioWrapper();

            void playSound(const std::string &path);
        private:
            ma_engine _engine;
            ma_result _result;
    };
}
