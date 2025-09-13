#pragma once

#include <raylib.h>

class Renderable {
	private:
		Texture2D texture;
		Vector2 origin;
		Rectangle sourceRect;
		Rectangle destRect;
		float rotation = 0.0f;
		Color tint = WHITE;

	public:
		Renderable(const Texture2D& texture, const Rectangle& sourceRect, const Rectangle& destRect, const Vector2& origin)
			: texture(texture), sourceRect(sourceRect), destRect(destRect), origin(origin) { }

		virtual ~Renderable() = default;

		virtual void setPosition(float x, float y) { destRect.x = x; destRect.y = y; }	
		virtual void setRotation(float angle) { rotation = angle; }
		virtual void setTint(Color color) { tint = color; }
		
		virtual Rectangle getPosition() const { return destRect; }

		virtual void render() { DrawTexturePro(texture,sourceRect,destRect,origin,rotation,tint); }
};