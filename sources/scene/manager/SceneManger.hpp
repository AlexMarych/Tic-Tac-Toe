#pragma once

#include "scene/BaseScene.hpp"
#include <vector>
#include <memory>
#include "../../core/patterns/State/StateMachine.hpp"


class SceneManager : StateMachine {
	private:
		float timeScale = 1.0f;

	public:	
		SceneManager(BaseScene* firstScene) { setState(static_cast<IState&>(*firstScene)); }

		~SceneManager() 
		{
			if (auto current = getCurrentState())
				current->exit();
		}

		void update(float deltaTime) 
		{ 
			if (auto current = getCurrentState()) 
				current->tick(deltaTime * timeScale);
		}

		void setTimeScale(float scale) { timeScale = scale; }
};