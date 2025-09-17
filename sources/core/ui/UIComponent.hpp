#pragma once

#include "raygui.h"
#include "raylib.h"
#include "../gameObject/Renderable.hpp"
#include <string>


class UIComponent : public Renderable
{
private:

	std::string text;
	bool visible = true;
	Rectangle bounds;
	
	bool static guiSliderDragging;
public:
	UIComponent(const Texture2D& texture, const Rectangle& destRect, const char* text)
		: Renderable(texture, destRect), text(text), bounds(destRect) {}

	void setVisible(bool isVisible) { visible = isVisible; }
	void setText(std::string newText) { text = newText; }
	

	virtual bool isInBounds(Vector2& point) { return CheckCollisionPointRec(point, bounds); }

	virtual void update() {}
	virtual void render() override { Renderable::render(); }

	bool static isSliderDragging() { return guiSliderDragging; }
	bool isVisible() const { return visible; }
};