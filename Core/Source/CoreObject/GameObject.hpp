#pragma once

#include "IUpdatable.hpp"
#include "Renderable.hpp"
#include <string>

namespace Core {

	class GameObject : public IUpdatable, public Renderable {
	private:
		bool active{true};
		std::string name;

	public:
		GameObject() noexcept = default;

		explicit GameObject(const Texture2D& texture, const std::string& name, const Rectangle& destRect) 
			: Renderable(texture, destRect), active(true), name(name)
		{
		}

		~GameObject() noexcept override = default;

		
		void update(float) override {} 

		
		void setActive(bool isActive) noexcept { active = isActive; }
		bool isActive() const noexcept { return active; }

		
		void setName(const std::string& newName) { name = newName; }
		const std::string& getName() const noexcept { return name; }

		
		using Renderable::setPosition; 
		void setPosition(const Rectangle& rect) { Renderable::setPosition(rect.x, rect.y); }

		
	};

} 