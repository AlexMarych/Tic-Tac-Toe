#pragma once

#include "raylib.h"
#include <string>
#include "core/utils/DebugUtils.hpp"

namespace Audio
{
class AudioSource
{
private:
    Sound sound{};
    bool loaded{false};

public:
    AudioSource() noexcept = default;
    virtual ~AudioSource() noexcept { unload(); }

    AudioSource(const AudioSource&) = delete;
    AudioSource& operator=(const AudioSource&) = delete;

    AudioSource(AudioSource&& other) noexcept
        : sound(other.sound), loaded(other.loaded)
    {
        other.sound = {};
        other.loaded = false;
    }

    AudioSource& operator=(AudioSource&& other) noexcept
    {
        if (this != &other) {
            unload();
            sound = other.sound;
            loaded = other.loaded;
            other.sound = {};
            other.loaded = false;
        }
        return *this;
    }

    
    bool loadFromFile(const std::string& filePath)
    {
        if (loaded) unload();
        std::string fullPath = std::string(ASSETS_PATH) + filePath;
        sound = LoadSound(fullPath.c_str());
        loaded = (sound.frameCount != 0 || sound.stream != 0);
        if (!loaded) {
            DebugUtils::println(std::string("AudioSource: failed to load '") + fullPath + "'");
        }
        return loaded;
    }

    static AudioSource createFromFile(const std::string& filePath)
    {
        AudioSource src;
        src.loadFromFile(filePath);
        return src;
    }

    void unload() noexcept
    {
        if (!loaded) return;
        stop();
        UnloadSound(sound);
        sound = {};
        loaded = false;
    }

    void play()
    {
        if (!loaded) {
            DebugUtils::println("AudioSource::play: sound not loaded");
            return;
        }
        DebugUtils::println("AudioSource: play");
        PlaySound(sound);
    }

    void pause()
    {
        if (isPlaying()) PauseSound(sound);
    }

    void resume()
    {
        if (!isPlaying() && loaded) ResumeSound(sound);
    }

    void stop()
    {
        if (isPlaying()) StopSound(sound);
    }

    bool isPlaying() const
    {
        if (!loaded) return false;
        return IsSoundPlaying(sound);
    }

    bool isLoaded() const noexcept { return loaded; }
};
} 