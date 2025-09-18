#pragma once

#include "Renderable.hpp"

class GameObject {

public:
	virtual ~GameObject() = 0;
	virtual void update(float deltaTime) {}
	virtual void update() {}

};