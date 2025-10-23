#pragma once

#include <raylib.h>
#include <string>
#include "Scene/manager/SceneManager.h"

namespace Core {

	struct GameConfig 
	{
		int screenWidth = 800;
		int screenHeight = 600;
		int fps = 60;
		std::string windowTitle = "Game";
	};

	class Game {
	public:
		explicit Game(const GameConfig& cfg);
		~Game() noexcept;

		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;
		Game(Game&&) noexcept = default;
		Game& operator=(Game&&) noexcept = default;

		void stop() noexcept;
		void Run();

		inline Scene::SceneManager* getSceneManager() const noexcept { return m_sceneManager.get(); }
		static inline const GameConfig& GetConfig() noexcept { return s_config; }
		

	private:
		bool m_isRunning{};
		GameConfig m_config{};
		std::unique_ptr<Scene::SceneManager> m_sceneManager{};

		void initWindow();
		void shutdown() noexcept;

		static inline GameConfig s_config{};
	};

}