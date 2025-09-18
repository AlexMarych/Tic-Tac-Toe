#pragma once

#include "../../patterns/State/StateMachine.hpp"
#include "../../gameObject/Renderable.hpp"
#include "raylib.h"
#include <string>
#include <map>

class AnimationState : public IState , public Renderable
{
private: 
	Texture2D animationSheet;

	int frame = 0;
	float runingTime = .0f;
	float width, height;
	int maxFrame;
	float updateTime = 1.0f / 12.0f;
	

public:
	AnimationState() {};

	AnimationState(const Texture2D& texture, const Rectangle& destRect, float width, float height, int maxFrame)
		: Renderable(texture, destRect),  width(width), height(height), maxFrame(maxFrame) {};

	void tick(float deltaTime) override
	{
		runingTime += deltaTime;
		if (runingTime >= updateTime)
		{
			frame++;
			runingTime = 0.0f;
			if (frame > maxFrame) frame = 0;
		}

		Rectangle source{ frame * width, height, width, height };
		DrawTexturePro(getTexture(), source, getPosition(), getOrigin(), getRotation(), getTint());
	};

};

class AnimationStateMachine : public StateMachine
{

};