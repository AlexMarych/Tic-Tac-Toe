#pragma once

#include "raygui.h"
#include "raylib.h"
#include "CoreObject/GameObject.hpp"
#include <string>

namespace UI {

	class UIComponent : public Core::GameObject
	{
	private:

		bool visible {true};
		Rectangle bounds;

		static bool guiSliderDragging;
	public:
		explicit UIComponent(const Texture2D& texture, const Rectangle& destRect) noexcept
			: Core::GameObject(texture, std::string(), destRect)
			, visible(true)
		{
		}

		~UIComponent() noexcept override = default;

		void setVisible(bool isVisible) noexcept { visible = isVisible; }
		bool isVisible() const noexcept { return visible; }


		virtual bool isInBounds(Vector2& point) { return CheckCollisionPointRec(point, bounds); }

		virtual void update(float deltaTime) override { GameObject::update(deltaTime); }
		virtual void render() override { Renderable::render(); }

		bool static isSliderDragging() noexcept { return guiSliderDragging; }

	};

}