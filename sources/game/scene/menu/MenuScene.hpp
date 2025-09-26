#pragma once

#include "../core/scene/BaseScene.hpp"
#include <string>
#include <map>
#include "raygui.h"

class MenuScene : public BaseScene {
private:

	Texture2D backgroundTexture;
	std::string titleText = "Angry Pirates";
	std::map<std::string, int*> menuOptions;

public:
	MenuScene();
	virtual ~MenuScene() {};
	virtual void tick(float deltaTime) override;
	virtual void enter() override;
	virtual void exit() override;
	void setTitleText(const std::string& title) { titleText = title; }
	

};