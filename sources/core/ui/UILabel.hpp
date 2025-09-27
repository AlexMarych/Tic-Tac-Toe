#pragma once

#include "../coreObject/Renderable.hpp"
#include <string>

namespace UI {

	class UILabel : public Renderable
	{
	private:
		std::string text;
		int fontSize = 20;
		int spacing = 0;
		Color color = BLACK;
		Font font = GetFontDefault();

	public:
		UILabel(const std::string& text, const Rectangle& destRect)
			: Renderable(destRect), text(text) {
		}

		void setSpacing(int newSpacing) { spacing = newSpacing; }
		void setText(const std::string& newText) { text = newText; }
		void setFontSize(int newFontSize) { fontSize = newFontSize; }
		void setColor(Color newColor) { color = newColor; }
		std::string getText() const { return text; }
		int getFontSize() const { return fontSize; }
		Color getColor() const { return color; }

		void render() override
		{
			DrawTextPro(font, text.c_str(), { getPosition().x, getPosition().y }, getOrigin(), getRotation(), fontSize, spacing, color);
		}

	};

}
