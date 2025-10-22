
#include "Renderable.h"

namespace Core {

    Renderable::Renderable(const Texture2D& texture,
        const Rectangle& sourceRect,
        const Rectangle& destRect,
        const Vector2& origin) noexcept
        : m_texture(texture)
        , m_origin(origin)
        , m_sourceRect(sourceRect)
        , m_destRect(destRect)
    {
    }

    Renderable::Renderable(const Texture2D& texture, const Rectangle& destRect) noexcept
        : m_texture(texture)
        , m_origin{ 0.0f, 0.0f }
        , m_sourceRect{ 0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height) }
        , m_destRect(destRect)
    {
    }

    Renderable::Renderable(const Rectangle& destRect) noexcept
        : m_texture{}
        , m_origin{ 0.0f, 0.0f }
        , m_sourceRect{ 0.0f, 0.0f, 0.0f, 0.0f }
        , m_destRect(destRect)
    {
    }

    void Renderable::render()
    {
        DrawTexturePro(m_texture, m_sourceRect, m_destRect, m_origin, m_rotation, m_tint);
    }

} 