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
	std::vector<std::shared_ptr<Renderable>> renderObjects;
	std::vector<std::shared_ptr<IUpdatable>> updateObjects;

public:
	BaseScene() = default;
	virtual ~BaseScene();
	virtual void tick(float deltaTime) override;

	virtual void enter() override;
	virtual void exit() override;

	template <typename T>
	void addObject(const std::shared_ptr<T>& obj) {
		if (auto u = std::dynamic_pointer_cast<IUpdatable>(obj)) {
			updateObjects.push_back(u);
		}
		if (auto r = std::dynamic_pointer_cast<Renderable>(obj)) {
			renderObjects.push_back(r);
		}
	}

	void setName(const std::string& sceneName) { name = sceneName; }

	std::string getName() const { return name; }

};
