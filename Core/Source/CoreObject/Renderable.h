#pragma once

#include <raylib.h>
#include "IRenderable.h"

namespace Core {

    class Renderable : public IRenderable {

    public:
        Renderable() noexcept = default;

        Renderable(const Texture2D& texture,
            const Rectangle& sourceRect,
            const Rectangle& destRect,
            const Vector2& origin = { 0.0f, 0.0f }) noexcept
            : m_texture(texture)
            , m_origin(origin)
            , m_sourceRect(sourceRect)
            , m_destRect(destRect)
        {
        }

        explicit Renderable(const Texture2D& texture, const Rectangle& destRect) noexcept
            : m_texture(texture)
            , m_origin{ 0.0f, 0.0f }
            , m_sourceRect{ 0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height) }
            , m_destRect(destRect)
        {
        }

        explicit Renderable(const Rectangle& destRect) noexcept
            : m_texture{}
            , m_origin{ 0.0f, 0.0f }
            , m_sourceRect{ 0.0f, 0.0f, 0.0f, 0.0f }
            , m_destRect(destRect)
        {
        }

        ~Renderable() noexcept override = default;

        void setOrigin(const Vector2& pivot) noexcept { m_origin = pivot; }
        void setPosition(float x, float y) noexcept { m_destRect.x = x; m_destRect.y = y; }
        void setPosition(const Rectangle& rect) noexcept { m_destRect = rect; }
        void setRotation(float angle) noexcept { m_rotation = angle; }
        void setTint(Color color) noexcept { m_tint = color; }
        void setSourceRect(const Rectangle& src) noexcept { m_sourceRect = src; }
        void setTexture(const Texture2D& tex) noexcept { m_texture = tex; }

        float getRotation() const noexcept { return m_rotation; }
        Color getTint() const noexcept { return m_tint; }
        Rectangle getPosition() const noexcept { return m_destRect; }
        Vector2 getOrigin() const noexcept { return m_origin; }
        const Texture2D& getTexture() const noexcept { return m_texture; }
        Rectangle getSourceRect() const noexcept { return m_sourceRect; }


        virtual void render() override { DrawTexturePro(m_texture, m_sourceRect, m_destRect, m_origin, m_rotation, m_tint); }

    private:
        Texture2D m_texture{};
        Vector2 m_origin{ 0.0f, 0.0f };
        Rectangle m_sourceRect{ 0.0f, 0.0f, 0.0f, 0.0f };
        Rectangle m_destRect{ 0.0f, 0.0f, 0.0f, 0.0f };
        float m_rotation{ 0.0f };
        Color m_tint{ WHITE };
    };
}