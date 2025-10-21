#pragma once

#include <raylib.h>
#include "IRenderable.hpp"

namespace Core {

    class Renderable : public IRenderable {
    private:
        Texture2D texture{};
        Vector2 origin{ 0.0f, 0.0f };
        Rectangle sourceRect{ 0.0f, 0.0f, 0.0f, 0.0f };
        Rectangle destRect{ 0.0f, 0.0f, 0.0f, 0.0f };
        float rotation{ 0.0f };
        Color tint{ WHITE };

    public:
        Renderable() noexcept = default;

        Renderable(const Texture2D& texture,
            const Rectangle& sourceRect,
            const Rectangle& destRect,
            const Vector2& origin = { 0.0f, 0.0f }) noexcept
            : texture(texture)
            , origin(origin)
            , sourceRect(sourceRect)
            , destRect(destRect)
        {
        }

        explicit Renderable(const Texture2D& texture, const Rectangle& destRect) noexcept
            : texture(texture)
            , origin{ 0.0f, 0.0f }
            , sourceRect{ 0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height) }
            , destRect(destRect)
        {
        }

        explicit Renderable(const Rectangle& destRect) noexcept
            : texture{}
            , origin{ 0.0f, 0.0f }
            , sourceRect{ 0.0f, 0.0f, 0.0f, 0.0f }
            , destRect(destRect)
        {
        }

        ~Renderable() noexcept override = default;

        void setOrigin(const Vector2& pivot) noexcept { origin = pivot; }
        void setPosition(float x, float y) noexcept { destRect.x = x; destRect.y = y; }
        void setPosition(const Rectangle& rect) noexcept { destRect = rect; }
        void setRotation(float angle) noexcept { rotation = angle; }
        void setTint(Color color) noexcept { tint = color; }
        void setSourceRect(const Rectangle& src) noexcept { sourceRect = src; }
        void setTexture(const Texture2D& tex) noexcept { texture = tex; }

        float getRotation() const noexcept { return rotation; }
        Color getTint() const noexcept { return tint; }
        Rectangle getPosition() const noexcept { return destRect; }
        Vector2 getOrigin() const noexcept { return origin; }
        const Texture2D& getTexture() const noexcept { return texture; }
        Rectangle getSourceRect() const noexcept { return sourceRect; }


        virtual void render() override { DrawTexturePro(texture, sourceRect, destRect, origin, rotation, tint); }
    };
}