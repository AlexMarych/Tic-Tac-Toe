#pragma once

#include "raygui.h"
#include "raylib.h"
#include "../coreObject/GameObject.hpp"
#include <string>

namespace UI {

	class UIComponent : public GameObject, public Renderable
	{
	private:

		bool visible = true;
		Rectangle bounds;

		bool static guiSliderDragging;
	public:
		UIComponent(const Texture2D& texture, const Rectangle& destRect)
			: Renderable(texture, destRect), bounds(destRect) {
		}

		void setVisible(bool isVisible) { visible = isVisible; }


		virtual bool isInBounds(Vector2& point) { return CheckCollisionPointRec(point, bounds); }

		virtual void update() override { GameObject::update(); }
		virtual void render() override { Renderable::render(); }

		bool static isSliderDragging() { return guiSliderDragging; }
		bool isVisible() const { return visible; }
	};

}