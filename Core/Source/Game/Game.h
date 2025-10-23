#pragma once

#include <raylib.h>
#include <string>
#include "Scene/manager/SceneManager.h"

namespace Core {

	constexpr int DEFAULT_SCREEN_WIDTH = 800;
	constexpr int DEFAULT_SCREEN_HEIGHT = 600;
	constexpr int DEFAULT_FPS = 60;
	constexpr char* DEFAULT_WINDOW_TITLE = "Game";

	struct GameConfig 
	{
		int screenWidth = DEFAULT_SCREEN_WIDTH;
		int screenHeight = DEFAULT_SCREEN_HEIGHT;
		int fps = DEFAULT_FPS;
		std::string windowTitle = DEFAULT_WINDOW_TITLE;
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