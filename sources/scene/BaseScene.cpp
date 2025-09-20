#include "BaseScene.hpp"

BaseScene::~BaseScene() {
	updateObjects.clear();
	renderObjects.clear();
}

void BaseScene::tick(float deltaTime)  {
	for (auto obj : updateObjects) {
		obj->update(deltaTime);
	}
	
	for (auto obj : renderObjects) {
		obj->render();
	}
}

void BaseScene::enter() {
	printf("Entering scene: %s\n", name.c_str());
}

void BaseScene::exit()  {
	printf("Exiting scene: %s\n", name.c_str());
}