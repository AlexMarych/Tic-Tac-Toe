#pragma once

#include "raygui.h"
#include "raylib.h"
#include "CoreObject/GameObject.h"
#include <string>

namespace UI {

	class UIComponent : public Core::GameObject
	{
	
	public:
		explicit UIComponent(const Texture2D& texture, const std::string& text, const Rectangle& destRect) noexcept;
		virtual ~UIComponent() noexcept override;

		inline void setVisible(bool isVisible) noexcept { m_visible = isVisible; }
		inline bool isVisible() const noexcept { return m_visible; }


		virtual bool isInBounds(const Vector2& point) const;

		virtual void update(float deltaTime) override;
		virtual void render() override;

		inline bool static isSliderDragging() noexcept { return s_guiSliderDragging; }

	private:
		bool m_visible{ true };
		Rectangle m_bounds{};

		static bool s_guiSliderDragging;
	};

}