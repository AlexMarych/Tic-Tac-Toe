#pragma once

#include "raylib.h"
#include <string>
#include <iostream>

namespace Audio
{
	class AudioSource
	{
	private:
		Sound sound;
		bool isLoaded = false;

	public:
		AudioSource() {}
		virtual ~AudioSource() = default;

		static bool LoadFromFile(const char* filePath, AudioSource* source)
		{
			if (source->isLoaded) source->Unload();

			std::string fullPath = std::string(ASSETS_PATH) + filePath;
			source->sound = LoadSound(fullPath.c_str());
			source->isLoaded = true;
			return source->isLoaded;
		}

		virtual void Unload() {
			this->Stop();
			if (isLoaded) {
				UnloadSound(this->sound);
				isLoaded = false;
			}
		}

		virtual void Play() 
		{ 
			std::cout << "Playing sound" << std::endl;
			PlaySound(this->sound); 
		}
		virtual void Pause() { if (IsPlaying()) PauseSound(this->sound); }
		virtual void Resume() { if (!IsPlaying()) ResumeSound(this->sound); }
		virtual void Stop() { if(IsPlaying()) StopSound(this->sound);}
		virtual bool IsPlaying() const { return IsSoundPlaying(sound); };
		
	};
}