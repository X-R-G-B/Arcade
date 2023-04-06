/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MiniAudioWrapper
*/

#include <stdexcept>
#define MINIAUDIO_IMPLEMENTATION
#include "MiniAudioWrapper.hpp"

MiniAudio::MiniAudioWrapper::MiniAudioWrapper()
{
    _result = ma_engine_init(NULL, &_engine);
    if (_result != MA_SUCCESS) {
        std::runtime_error("Failed to initialize MiniAudio engine");
    }
}

MiniAudio::MiniAudioWrapper::~MiniAudioWrapper()
{
    ma_engine_uninit(&_engine);
}

void MiniAudio::MiniAudioWrapper::playSound(const std::string &path)
{
    ma_engine_play_sound(&_engine, path.data(), NULL);
}
