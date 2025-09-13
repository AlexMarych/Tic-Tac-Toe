#include "SceneManger.hpp"
#include "utils/DebugUtils.hpp"


SceneManager::~SceneManager() {
	if (currentScene) {
		currentScene->exit();
	}

}

void SceneManager::setScene(BaseScene* scene)
{
	if (!scene) {
		DebugUtils::println("scene is null");
		return;
	}
		
	currentScene->exit();

	currentScene = scene;

	currentScene->enter();
}
