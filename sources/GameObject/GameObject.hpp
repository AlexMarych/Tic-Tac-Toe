#pragma once

#include "Renderable.hpp"

class GameObject : Renderable {

public:
	virtual ~GameObject() = 0;
	virtual void update(float deltaTime);
	virtual void render() override;

};