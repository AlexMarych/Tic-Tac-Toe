#include "UILabel.h"

namespace UI {

    UILabel::UILabel(const std::string& text, const Rectangle& destRect, const Font& font) noexcept
        : Core::Renderable(destRect)
        , m_text(text)
        , m_fontSize(20)
        , m_spacing(2)
        , m_color(BLACK)
        , m_textFont(font)
    {
    }

    UILabel::~UILabel() noexcept = default;

    void UILabel::render()
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

}
