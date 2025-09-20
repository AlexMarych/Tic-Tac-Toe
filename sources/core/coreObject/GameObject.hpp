#pragma once

#include "IUpdatable.hpp"
#include "Renderable.hpp"
#include <string>

class GameObject : public IUpdatable, public Renderable
{
private:

	std::string name;
	Vector2 position = { .0f, .0f };

public:
	GameObject() = default;
	GameObject(const Texture& texture, const std::string name, const Vector2& position)
		: Renderable(texture, { position.x, position.y, (float)texture.width, (float)texture.height }), name(name), position(position) 
	{
	}

	virtual ~GameObject() = default;

	virtual void setPosition(float x, float y) { position.x = x; position.y = y; }
	virtual void setPosition(Vector2 pos) { position = pos; }

};