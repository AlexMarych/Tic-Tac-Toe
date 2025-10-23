
#include "Renderable.h"
#include "Game/Game.h"

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

    void Renderable::scale() noexcept {
        m_scaleX = (float)GetScreenWidth() / (float)Game::GetConfig().screenWidth;
        m_scaleY = (float)GetScreenHeight() / (float)Game::GetConfig().screenHeight;
    }

    void Renderable::render()
    {
        scale();
		
        DrawTexturePro(
            m_texture,
            m_sourceRect,
            {
                    m_destRect.x * m_scaleX,
                    m_destRect.y * m_scaleY,
                    m_destRect.width * m_scaleX,
                    m_destRect.height * m_scaleY
            },
            m_origin, 
            m_rotation, 
            m_tint);
    }

} 