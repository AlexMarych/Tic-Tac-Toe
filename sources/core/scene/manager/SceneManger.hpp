#pragma once

#include "core/scene/BaseScene.hpp"
#include <vector>
#include <memory>
#include "core/patterns/State/StateMachine.hpp"

namespace Scene {

	class SceneManager : StateMachine {
	private:
		float timeScale = 1.0f;

	public:
		SceneManager() {}

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

		template<typename TScene>
		void setScene(TScene& newState)
		{
			static_assert(std::is_base_of_v<BaseScene, TScene>,
				"TScene must derive from BaseScene");

			setState(newState);
		}
	};

}