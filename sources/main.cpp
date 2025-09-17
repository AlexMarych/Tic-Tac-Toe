#include <raylib.h>
#include <raygui.h>
#include "Constants.hpp"
#include "scene/manager/SceneManger.hpp"
#include <scene/LevelScene.hpp>
#include <memory>


int main() {
	
	InitWindow(
		AppConstants::ScreenWidth,
		AppConstants::ScreenHeight,
		AppConstants::WindowTitle.c_str()
	);

	auto levelScene1 = new BaseScene();
	levelScene1->setName("Level 1");


	auto sceneManager = new SceneManager(levelScene1);


	SetTargetFPS(AppConstants::TargetFPS);             

	

	while (!WindowShouldClose())   
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
	
		sceneManager->update(GetFrameTime());

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
