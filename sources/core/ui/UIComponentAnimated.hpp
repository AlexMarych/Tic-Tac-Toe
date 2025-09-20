#pragma once

#include "UIComponent.hpp"
#include "../animation/Animatable.hpp"

class UIComponentAnimated : public UIComponent, public Animatable{

public:
	UIComponentAnimated(const Texture2D& texture, const Rectangle& destRect) 
		: UIComponent(texture, destRect), Animatable(texture, destRect, 0)
	{
	}

	virtual void addAnimation(const std::string& name, const AnimationState& animation)
	{
		Animatable::addAnimation(name, animation);
	}
};