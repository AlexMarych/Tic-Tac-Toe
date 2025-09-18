#pragma once

#include "../UIComponentAnimated.hpp"
#include "raygui.h"
#include <functional>

enum class ButtonState {
	NORMAL = 0,
	FOCUSED,
	PRESSED,
	HOLDED,
	DISABLED
};

class UIButton : public UIComponentAnimated
{
private:
	ButtonState state = ButtonState::NORMAL;
	std::function<void()> onClick;
	
public:
	UIButton(const Texture2D& texture, const Rectangle& destRect) 
		: UIComponentAnimated(texture, destRect) 
	{ state = ButtonState::NORMAL; }

	bool isPressed() const { return state == ButtonState::PRESSED; }
	bool isHolded() const { return state == ButtonState::HOLDED; }

	void setState(ButtonState newState) { state = newState; }

	void setOnClick(std::function<void()> handler) 
	{
		onClick = handler;
	}

	void handleEvent() {
		if (onClick) 
		{
			onClick();
		}
	}


	void update() override;
	void render() override;

};