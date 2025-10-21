#pragma once

#include "raylib.h"
#include "CoreObject/Renderable.h"
#include <string>

namespace UI {

    class UILabel : public Core::Renderable 
    {
    
    public:
        explicit UILabel(const std::string& text, const Rectangle& destRect, const Font& font = GetFontDefault()) noexcept
            : Core::Renderable(destRect)
            , m_text(text)
            , m_fontSize(20)
            , m_spacing(0)
            , m_color(BLACK)
            , m_textFont(font)
        {
        }

        ~UILabel() noexcept override = default;

        void setSpacing(int newSpacing) noexcept { m_spacing = newSpacing; }
        void setText(const std::string& newText) { m_text = newText; }
        void setFontSize(int newFontSize) noexcept { m_fontSize = newFontSize; }
        void setColor(Color newColor) noexcept { m_color = newColor; }
        void setFont(const Font& font) noexcept { m_textFont = font; }

        const std::string& getText() const noexcept { return m_text; }
        int getFontSize() const noexcept { return m_fontSize; }
        Color getColor() const noexcept { return m_color; }
        const Font& getFont() const noexcept { return m_textFont; }

        void render() override
        {
            const Rectangle pos = getPosition();
            DrawTextPro(m_textFont,
                m_text.c_str(),
                { pos.x, pos.y },
                getOrigin(),
                getRotation(),
                static_cast<float>(m_fontSize),
                m_spacing,
                m_color);
        }

    private:
        std::string m_text{};
        int m_fontSize{};
        int m_spacing{};
        Color m_color{};
        Font m_textFont{};
    };

} 
