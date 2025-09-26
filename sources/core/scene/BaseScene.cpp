#include "BaseScene.hpp"

BaseScene::~BaseScene() {
	updateObjects.clear();
	renderObjects.clear();
}

void BaseScene::enter() {
	printf("Entering scene: %s\n", name.c_str());
}

void BaseScene::exit()  {
	printf("Exiting scene: %s\n", name.c_str());
}