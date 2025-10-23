#include "UILabel.h"

namespace UI {

    UILabel::UILabel( const std::string& text, const Rectangle& destRect, const Font& font ) noexcept
        : Core::Renderable(destRect)
        , m_text(text)
        , m_textFont(font)
    {
		setFontSize(14);
        setSpacing(2);
		setColor(BLACK);
    }

    UILabel::~UILabel() noexcept = default;

    void UILabel::render()
    {
		Renderable::scale();

        const Rectangle pos = getPosition();
        DrawTextPro(m_textFont,
            m_text.c_str(),
            { pos.x * m_scaleX, pos.y * m_scaleY },
            getOrigin(),
            getRotation(),
            static_cast<float>(m_fontSize) * std::min(m_scaleX, m_scaleY),
            m_spacing * std::min(m_scaleX, m_scaleY),
            m_color);
    }

}
