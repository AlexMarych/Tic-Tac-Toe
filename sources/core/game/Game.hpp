#pragma once

#include <raylib.h>
#include <string>
#include "core/scene/manager/SceneManger.hpp"

namespace Core {

	struct GameConfig
	{
		int SCREEN_WIDTH = 800;
		int SCREEN_HEIGHT = 600;
		int FPS = 60;
		std::string WINDOW_TITLE = "Game";
	};

	class Game
	{
	private: 
		bool isRunning;
		GameConfig config;
		SceneManager* sceneManager;

	public:
		Game(const GameConfig& config) : config(config) {
			SetConfigFlags(FLAG_WINDOW_RESIZABLE);
			InitWindow(config.SCREEN_WIDTH, config.SCREEN_HEIGHT, config.WINDOW_TITLE.c_str());
			SetTargetFPS(config.FPS);
			sceneManager = new SceneManager();
		}

		~Game() {
			CloseWindow();
		}

		
		void Stop() {
			isRunning = false;
		}

		void Run() {
			isRunning = true;

			while (isRunning) {

				if (WindowShouldClose()) {
					Stop();
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