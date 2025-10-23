#include "UILabel.h"

namespace UI {

    constexpr int DEFAULT_FONT_SIZE = 14;
    constexpr int DEFAULT_SPACING = 2;

    UILabel::UILabel( const std::string& text, const Rectangle& destRect, const Font& font ) noexcept
        : Core::Renderable(destRect)
        , m_text(text)
        , m_textFont(font)
		, m_fontSize(DEFAULT_FONT_SIZE)
		, m_spacing(DEFAULT_SPACING)
		, m_color(defaultColor)
    {
    }

    UILabel::~UILabel() noexcept = default;

    void UILabel::render()
    {
		Renderable::scale();

        const float scaledFontSize = m_fontSize * std::min(m_scaleX, m_scaleY);
        const float scaledSpacing = m_spacing * std::min(m_scaleX, m_scaleY);

        const Rectangle pos = getPosition();
        DrawTextPro(m_textFont,
            m_text.c_str(),
            { pos.x * m_scaleX, pos.y * m_scaleY },
            getOrigin(),
            getRotation(),
            scaledFontSize,
            scaledSpacing,
            m_color);
    }

}
