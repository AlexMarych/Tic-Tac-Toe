
#include "UIButton.hpp"
#include "raylib.h"
#include "raygui.h"
#include "../UIComponent.hpp"

bool UIComponent::guiSliderDragging = false;

void UIButton::update() {
    if ((state != ButtonState::DISABLED) || UIComponent::isSliderDragging()) return;

    state = ButtonState::NORMAL;
    
    
    Vector2 mousePoint = GetMousePosition();

    if (UIComponent::isInBounds(mousePoint))
    {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) state = ButtonState::HOLDED;
        else state = ButtonState::FOCUSED;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            handleEvent();
            state = ButtonState::PRESSED;
        }
    }
    
}

void UIButton::render() {
	if (!UIComponent::isVisible()) return;
	
    switch (state)
    {
    case ButtonState::PRESSED:
        Animatable::Play("pressed");
        break;
    case ButtonState::DISABLED:
        Animatable::Play("disabled");
        break;
    case ButtonState::FOCUSED:
        Animatable::Play("focused");
        break;
    case ButtonState::HOLDED:
        Animatable::Play("pressed");
        break;
    default:
		Animatable::Play("idle");
        break;
    }
}