#pragma once

#include "UIComponent.hpp"
#include "../animation/Animatable.hpp"

class UIComponentAnimated : public UIComponent, public Animatable{

public:
	UIComponentAnimated(const Texture2D& texture, const Rectangle& destRect) 
		: UIComponent(texture, destRect), Animatable()
	{
		auto anim = new AnimationState(texture, destRect, texture.width, texture.height, 0);
		addAnimation("idle", *anim);
	}

	virtual void addAnimation(const std::string& name, const AnimationState& animation)
	{
		Animatable::addAnimation(name, animation);
	}
};