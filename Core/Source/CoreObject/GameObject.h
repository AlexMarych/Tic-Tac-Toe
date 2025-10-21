#pragma once

#include "IUpdatable.h"
#include "Renderable.h"
#include <string>

namespace Core {

	class GameObject : public IUpdatable, public Renderable {

	public:
		GameObject() noexcept = default;

		explicit GameObject(const Texture2D& texture, const std::string& name, const Rectangle& destRect) 
			: Renderable(texture, destRect), m_active(true), m_name(name)
		{
		}

		~GameObject() noexcept override = default;

		
		void update(float) override {} 

		
		void setActive(bool isActive) noexcept { m_active = isActive; }
		bool isActive() const noexcept { return m_active; }

		
		void setName(const std::string& newName) { m_name = newName; }
		const std::string& getName() const noexcept { return m_name; }

		
		using Renderable::setPosition; 
		void setPosition(const Rectangle& rect) { Renderable::setPosition(rect.x, rect.y); }

	private:
		bool m_active{ true };
		std::string m_name{};
	};

} 