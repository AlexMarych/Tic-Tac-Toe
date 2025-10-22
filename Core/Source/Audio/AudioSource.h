#pragma once

#include "raylib.h"
#include <string>
#include "Utils/DebugUtils.h"

namespace Audio
{
    class AudioSource
    {
    public:
        AudioSource() noexcept = default;
        virtual ~AudioSource() noexcept;

        AudioSource(const AudioSource&) = delete;
        AudioSource& operator=(const AudioSource&) = delete;

        AudioSource(AudioSource&& other) noexcept;
        AudioSource& operator=(AudioSource&& other) noexcept;

        bool loadFromFile(const std::string& filePath);
        static AudioSource createFromFile(const std::string& filePath);
        void unload() noexcept;

        void play();
        void pause();
        void resume();
        void stop();

        bool isPlaying() const;
        inline bool isLoaded() const noexcept { return m_loaded; }
    private:
        Sound m_sound{};
        bool m_loaded{ false };
    };
}