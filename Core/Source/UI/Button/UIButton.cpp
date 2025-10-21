#include "UIButton.h"
#include "raylib.h"
#include "raygui.h"
#include "UI/UIComponent.h"

namespace UI {

    bool UIComponent::guiSliderDragging = false;

    void UIButton::update(float deltaTime) {
        if (state == ButtonState::DISABLED || UIComponent::isSliderDragging())
            return;

        state = ButtonState::NORMAL;

        Vector2 mousePoint = GetMousePosition();

        if (UIComponent::isInBounds(mousePoint)) {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                state = ButtonState::HOLDED;
            } else {
                state = ButtonState::FOCUSED;
            }

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                handleEvent();
                state = ButtonState::PRESSED;
            }
        }
    }

    void UIButton::render() {
        if (!UIComponent::isVisible())
            return;

        switch (state) {
        case ButtonState::PRESSED:
            Animatable::play("pressed");
            break;
        case ButtonState::DISABLED:
            Animatable::play("disabled");
            break;
        case ButtonState::FOCUSED:
            Animatable::play("focused");
            break;
        case ButtonState::HOLDED:
            Animatable::play("pressed");
            break;
        default:
            Animatable::play("idle");
            break;
        }

        UILabel::render();
    }
}