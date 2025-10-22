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
            const Vector2& origin = { 0.0f, 0.0f }) noexcept;

        explicit Renderable(const Texture2D& texture, const Rectangle& destRect) noexcept;
        explicit Renderable(const Rectangle& destRect) noexcept;

        virtual ~Renderable() noexcept override = default;

        inline void setOrigin(const Vector2& pivot) noexcept { m_origin = pivot; }
        inline void setPosition(float x, float y) noexcept { m_destRect.x = x; m_destRect.y = y; }
        inline void setPosition(const Rectangle& rect) noexcept { m_destRect = rect; }
        inline void setRotation(float angle) noexcept { m_rotation = angle; }
        inline void setTint(Color color) noexcept { m_tint = color; }
        inline void setSourceRect(const Rectangle& src) noexcept { m_sourceRect = src; }
        inline void setTexture(const Texture2D& tex) noexcept { m_texture = tex; }

        inline float getRotation() const noexcept { return m_rotation; }
        inline Color getTint() const noexcept { return m_tint; }
        inline Rectangle getPosition() const noexcept { return m_destRect; }
        inline Vector2 getOrigin() const noexcept { return m_origin; }
        inline const Texture2D& getTexture() const noexcept { return m_texture; }
        inline Rectangle getSourceRect() const noexcept { return m_sourceRect; }

        void render() override;
    private:
        Texture2D m_texture{};
        Vector2 m_origin{ 0.0f, 0.0f };
        Rectangle m_sourceRect{ 0.0f, 0.0f, 0.0f, 0.0f };
        Rectangle m_destRect{ 0.0f, 0.0f, 0.0f, 0.0f };
        float m_rotation{ 0.0f };
        Color m_tint{ WHITE };
    };
}