
#include "AudioSource.h"

namespace Audio
{
    AudioSource::~AudioSource() noexcept
    {
        unload();
    }

    AudioSource::AudioSource(AudioSource&& other) noexcept
        : m_sound(other.m_sound), m_loaded(other.m_loaded)
    {
        other.m_sound = {};
        other.m_loaded = false;
    }

    AudioSource& AudioSource::operator=(AudioSource&& other) noexcept
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

    bool isSoundValid(const Sound& sound) noexcept
    {
        bool hasFrames = (sound.frameCount != 0);
        bool hasBuffer = (sound.stream.buffer != nullptr);
        return hasFrames || hasBuffer;
	}

    bool AudioSource::loadFromFile(const std::string& filePath)
    {
        if (m_loaded) unload();
        auto fullPath = filePath;
        m_sound = LoadSound(fullPath.c_str());
        m_loaded = isSoundValid(m_sound);
        if (!m_loaded) {
            DebugUtils::println("AudioSource: failed to load '" + fullPath + "'");
        }
        return m_loaded;
    }

    AudioSource AudioSource::createFromFile(const std::string& filePath)
    {
        AudioSource src;
        src.loadFromFile(filePath);
        return src;
    }

    void AudioSource::unload() noexcept
    {
        if (!m_loaded) return;
        stop();
        UnloadSound(m_sound);
        m_sound = {};
        m_loaded = false;
    }

    void AudioSource::play()
    {
        if (!m_loaded) {
            DebugUtils::println("AudioSource::play: sound not loaded");
            return;
        }
        DebugUtils::println("AudioSource: play");
        PlaySound(m_sound);
    }

    void AudioSource::pause()
    {
        if (isPlaying()) PauseSound(m_sound);
    }

    void AudioSource::resume()
    {
        if (!isPlaying() && m_loaded) ResumeSound(m_sound);
    }

    void AudioSource::stop()
    {
        if (isPlaying()) StopSound(m_sound);
    }

    bool AudioSource::isPlaying() const
    {
        if (!m_loaded) return false;
        return IsSoundPlaying(m_sound);
    }
}