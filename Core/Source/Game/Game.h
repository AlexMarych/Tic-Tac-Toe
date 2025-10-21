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

	class Game
	{

	public:
		explicit Game(const GameConfig& cfg)
			: m_config(cfg)
			, m_sceneManager(std::make_unique<Scene::SceneManager>())
			, m_isRunning(false)
		{
			initWindow();
		}

		~Game() noexcept
		{
			shutdown();
		}

		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;
		Game(Game&&) noexcept = default;
		Game& operator=(Game&&) noexcept = default;

		
		void stop() noexcept 
		{
			m_isRunning = false;
		}

		void Run() {
			m_isRunning = true;

			while (m_isRunning) {

				if (WindowShouldClose()) {
					stop();
					break;
				}

				BeginDrawing();
				ClearBackground(RAYWHITE);
				
				m_sceneManager->update(GetFrameTime());

				EndDrawing();
			}
		}

	private:
		bool m_isRunning{};
		GameConfig m_config{};
		std::unique_ptr<Scene::SceneManager> m_sceneManager{};

		void initWindow()
		{
			SetConfigFlags(FLAG_WINDOW_RESIZABLE);
			InitWindow(m_config.screenWidth, m_config.screenHeight, m_config.windowTitle.c_str());
			SetTargetFPS(m_config.fps);
		}

		void shutdown() noexcept
		{
			if (m_sceneManager)
			{
				m_sceneManager.reset();
			}
			if (!m_isRunning)
			{
				CloseWindow();
			}
		}
	};

}