
#include "Renderable.h"
#include "Game/Game.h"

namespace Core {

    constexpr Vector2 DEFAULT_POSITION = {0, 0};
    constexpr Rectangle DEFAULT_DESTINATION_REC = {0, 0, 0, 0};

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
        , m_origin(DEFAULT_POSITION)
        , m_destRect(destRect)
    {
        auto width = static_cast<float>(texture.width);
		auto height = static_cast<float>(texture.height);
        m_sourceRect = { DEFAULT_POSITION.x, DEFAULT_POSITION.y, width, height };
    }

    Renderable::Renderable(const Rectangle& destRect) noexcept
        : m_texture()
        , m_origin(DEFAULT_POSITION)
        , m_sourceRect(DEFAULT_DESTINATION_REC)
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