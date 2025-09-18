#include "BaseScene.hpp"

BaseScene::~BaseScene() {
	objects.clear();
}

void BaseScene::tick(float deltaTime)  {
	for (auto& obj : objects) {
		obj->update(deltaTime);
		//obj->render();
	}
}

void BaseScene::enter() {
	printf("Entering scene: %s\n", name.c_str());
}

void BaseScene::exit()  {
	printf("Exiting scene: %s\n", name.c_str());
}