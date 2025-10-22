#pragma once

#include "raylib.h"
#include "CoreObject/Renderable.h"
#include <string>

namespace UI {

    class UILabel : public Core::Renderable 
    {
    public:
        explicit UILabel(const std::string& text, const Rectangle& destRect, const Font& font = GetFontDefault()) noexcept;
        ~UILabel() noexcept override;

        inline void setSpacing(int newSpacing) noexcept { m_spacing = newSpacing; }
        inline void setText(const std::string& newText) { m_text = newText; }
        inline void setFontSize(int newFontSize) noexcept { m_fontSize = newFontSize; }
        inline void setColor(Color newColor) noexcept { m_color = newColor; }
        inline void setFont(const Font& font) noexcept { m_textFont = font; }

        inline const std::string& getText() const noexcept { return m_text; }
        inline int getFontSize() const noexcept { return m_fontSize; }
        inline Color getColor() const noexcept { return m_color; }
        inline const Font& getFont() const noexcept { return m_textFont; }

        void render() override;

    private:
        std::string m_text{};
        int m_fontSize{};
        int m_spacing{};
        Color m_color{};
        Font m_textFont{};
    };

} 
