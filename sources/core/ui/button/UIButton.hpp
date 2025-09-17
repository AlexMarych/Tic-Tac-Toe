
#include "../UIComponent.hpp"
#include "raygui.h"

enum class ButtonState {
	NORMAL = 0,
	FOCUSED,
	PRESSED,
	HOLDED,
	DISABLED
};

class UIButton : public UIComponent
{
	ButtonState state = ButtonState::NORMAL;

public:

	bool isPressed() const { return state == ButtonState::PRESSED; }
	bool isHolded() const { return state == ButtonState::HOLDED; }

	void setState(ButtonState newState) { state = newState; }

	void update() override;
	void render() override;

};