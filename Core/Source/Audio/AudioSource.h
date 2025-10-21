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
        virtual ~AudioSource() noexcept { unload(); }

        AudioSource(const AudioSource&) = delete;
        AudioSource& operator=(const AudioSource&) = delete;

        AudioSource(AudioSource&& other) noexcept
            : m_sound(other.m_sound), m_loaded(other.m_loaded)
        {
            other.m_sound = {};
            other.m_loaded = false;
        }

        AudioSource& operator=(AudioSource&& other) noexcept
        {
            if (this != &other) {
                unload();
                m_sound = other.m_sound;
                m_loaded = other.m_loaded;
                other.m_sound = {};
                other.m_loaded = false;
            }
            return *this;
        }


        bool loadFromFile(const std::string& filePath)
        {
            if (m_loaded) unload();
            std::string fullPath = filePath;
            m_sound = LoadSound(fullPath.c_str());
            m_loaded = (m_sound.frameCount != 0 || m_sound.stream.buffer != nullptr);
            if (!m_loaded) {
                DebugUtils::println(std::string("AudioSource: failed to load '") + fullPath + "'");
            }
            return m_loaded;
        }

        static AudioSource createFromFile(const std::string& filePath)
        {
            AudioSource src;
            src.loadFromFile(filePath);
            return src;
        }

        void unload() noexcept
        {
            if (!m_loaded) return;
            stop();
            UnloadSound(m_sound);
            m_sound = {};
            m_loaded = false;
        }

        void play()
        {
            if (!m_loaded) {
                DebugUtils::println("AudioSource::play: sound not loaded");
                return;
            }
            DebugUtils::println("AudioSource: play");
            PlaySound(m_sound);
        }

        void pause()
        {
            if (isPlaying()) PauseSound(m_sound);
        }

        void resume()
        {
            if (!isPlaying() && m_loaded) ResumeSound(m_sound);
        }

        void stop()
        {
            if (isPlaying()) StopSound(m_sound);
        }

        bool isPlaying() const
        {
            if (!m_loaded) return false;
            return IsSoundPlaying(m_sound);
        }

        bool isLoaded() const noexcept { return m_loaded; }

    private:
        Sound m_sound{};
        bool m_loaded{ false };
    };
}