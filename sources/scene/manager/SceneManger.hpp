#pragma once

#include "scene/BaseScene.hpp"
#include <memory>


class SceneManager {
	private:
		BaseScene* currentScene;
		float timeScale = 1.0f;

	public:	
		SceneManager(BaseScene* firstScene)
			: currentScene(firstScene)
		{
			if (currentScene) {
				currentScene->enter();
			}
		}

		~SceneManager();

		void setScene(BaseScene* scene);
		
		void tick(float deltaTime) { if (currentScene) currentScene->tick(deltaTime * timeScale); }

		void setTimeScale(float scale) { timeScale = scale; }
};