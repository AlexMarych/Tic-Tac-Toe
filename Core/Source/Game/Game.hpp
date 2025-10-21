#pragma once

#include <raylib.h>
#include <string>
#include "Scene/manager/SceneManager.hpp"

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
	private: 
		bool isRunning;
		GameConfig config;
		std::unique_ptr<Scene::SceneManager> sceneManager;


		void initWindow()
		{
			SetConfigFlags(FLAG_WINDOW_RESIZABLE);
			InitWindow(config.screenWidth, config.screenHeight, config.windowTitle.c_str());
			SetTargetFPS(config.fps);
		}

		void shutdown() noexcept
		{
			if (sceneManager) 
			{
				sceneManager.reset();
			}
			if (!isRunning) 
			{
				CloseWindow();
			}
		}

	public:
		explicit Game(const GameConfig& cfg)
			: config(cfg)
			, sceneManager(std::make_unique<Scene::SceneManager>())
			, isRunning(false)
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
			isRunning = false;
		}

		void Run() {
			isRunning = true;

			while (isRunning) {

				if (WindowShouldClose()) {
					stop();
					break;
				}

				BeginDrawing();
				ClearBackground(RAYWHITE);
				
				sceneManager->update(GetFrameTime());

				EndDrawing();
			}
		}
	};

}