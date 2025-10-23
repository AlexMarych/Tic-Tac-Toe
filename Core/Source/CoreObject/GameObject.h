#pragma once

#include "IUpdatable.h"
#include "Renderable.h"
#include <string>

namespace Core {

	class GameObject : public virtual IUpdatable, public Renderable {

	public:
        explicit GameObject(const Texture2D& texture, const std::string& name, const Rectangle& destRect);

        ~GameObject() noexcept override = default;

        void update(float deltaTime) override;

        inline void setActive(bool isActive) noexcept { m_active = isActive; }
        inline bool isActive() const noexcept { return m_active; }

        inline void setName(const std::string& newName) { m_name = newName; }
        inline const std::string& getName() const noexcept { return m_name; }

        using Renderable::setPosition;
        void setPosition(const Rectangle& rect);
	private:
		bool m_active{ true };
		std::string m_name{};
	};

} 