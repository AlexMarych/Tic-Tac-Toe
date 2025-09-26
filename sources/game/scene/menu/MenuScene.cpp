#include "game/scene/menu/MenuScene.hpp"
#include "Constants.hpp"

MenuScene::MenuScene() {
	backgroundTexture = LoadTexture(AppConstants::GetAssetPath("menu_background.png").c_str());
	setName("MenuScene");
}

void MenuScene::tick(float deltaTime)
{
}

void MenuScene::enter()
{
}

void MenuScene::exit()
{
}
