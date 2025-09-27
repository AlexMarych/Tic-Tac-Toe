#pragma once

#include "IUpdatable.hpp"
#include "Renderable.hpp"
#include <string>

namespace Core {

	class GameObject : public IUpdatable, public Renderable
	{
	private:
		bool active = true;

		std::string name;
		Rectangle position = { .0f, .0f, .0f, .0f };

	public:
		GameObject() = default;
		GameObject(const Texture& texture, const std::string name, const Rectangle& position)
			: Renderable(texture, position), name(name), position(position)
		{
		}

		virtual ~GameObject() = default;

		virtual void setActive(bool isActive) { active = isActive; }
		virtual void setPosition(float x, float y) { position.x = x; position.y = y; }
		virtual void setPosition(Rectangle pos) { position = pos; }

	};

}