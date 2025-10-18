#pragma once

#include "raylib.h"
#include "../coreObject/Renderable.hpp"
#include <string>

namespace UI {

    class UILabel : public Core::Renderable 
    {
    private:
        std::string text;
        int fontSize;
        int spacing;
        Color color;
        Font textFont;
    
    public:
        explicit UILabel(const std::string& text, const Rectangle& destRect, const Font& font = GetFontDefault()) noexcept
            : Core::Renderable(destRect)
            , text(text)
            , fontSize(20)
            , spacing(0)
            , color(BLACK)
            , textFont(font)
        {
        }

        ~UILabel() noexcept override = default;

        void setSpacing(int newSpacing) noexcept { spacing = newSpacing; }
        void setText(const std::string& newText) { text = newText; }
        void setFontSize(int newFontSize) noexcept { fontSize = newFontSize; }
        void setColor(Color newColor) noexcept { color = newColor; }
        void setFont(const Font& font) noexcept { textFont = font; }

        const std::string& getText() const noexcept { return text; }
        int getFontSize() const noexcept { return fontSize; }
        Color getColor() const noexcept { return color; }
        const Font& getFont() const noexcept { return textFont; }

        void render() const override
        {
            const Rectangle pos = getPosition();
            DrawTextPro(textFont,
                text.c_str(),
                { pos.x, pos.y },
                getOrigin(),
                getRotation(),
                static_cast<float>(fontSize),
                spacing,
                color);
        }

    
    };

} 
