#pragma once

#include <raylib.h>

class Renderable {
	private:
		Texture2D texture;
		Vector2 origin = {.0f, .0f};
		Rectangle sourceRect;
		Rectangle destRect;
		float rotation = 0.0f;
		Color tint = WHITE;

	public:
		Renderable() {};

		Renderable(const Texture2D& texture, const Rectangle& sourceRect, const Rectangle& destRect, const Vector2& origin)
			: texture(texture), sourceRect(sourceRect), destRect(destRect), origin(origin) { }

		Renderable(const Texture2D& texture, const Rectangle& destRect)
			: texture(texture), sourceRect({ 0, 0, (float)texture.width, (float)texture.height }), destRect(destRect) {
		}

		virtual ~Renderable() = default;

		virtual void setOrigin(Vector2 pivot) { origin = pivot; }
		virtual void setPosition(float x, float y) { destRect.x = x; destRect.y = y; }	
		virtual void setRotation(float angle) { rotation = angle; }
		virtual void setTint(Color color) { tint = color; }
		
		virtual float getRotation() const { return rotation; }
		virtual Color getTint() const { return tint; }
		virtual Rectangle getPosition() const { return destRect; }
		virtual Vector2 getOrigin() const { return origin;  }
		virtual Texture2D getTexture() const { return texture; }

		virtual void render() { DrawTexturePro(texture,sourceRect,destRect,origin,rotation,tint); }
};