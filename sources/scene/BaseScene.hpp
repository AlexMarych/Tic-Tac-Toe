#pragma once

#include <vector>
#include "raylib.h"
#include "core/patterns/State/StateMachine.hpp"
#include <core/coreObject/GameObject.hpp>
#include <string>
#include <memory>


class BaseScene : public IState{

private:
	std::string name;

protected:
	std::vector<GameObject*> objects;

public:
	BaseScene() = default;
	virtual ~BaseScene();
	virtual void tick(float deltaTime) override;

	virtual void enter() override;
	virtual void exit() override;

	void setName(const std::string& sceneName) { name = sceneName; }

	std::string getName() const { return name; }

};
