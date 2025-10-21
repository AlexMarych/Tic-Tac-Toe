#include "UIButton.h"
#include "raylib.h"
#include "raygui.h"
#include "UI/UIComponent.h"

namespace UI {

    bool UIComponent::s_guiSliderDragging = false;

    void UIButton::update(float deltaTime) {
        if (m_state == ButtonState::DISABLED || UIComponent::isSliderDragging())
            return;

        m_state = ButtonState::NORMAL;

        Vector2 mousePoint = GetMousePosition();

        if (UIComponent::isInBounds(mousePoint)) {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                m_state = ButtonState::HOLDED;
            } else {
                m_state = ButtonState::FOCUSED;
            }

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                handleEvent();
                m_state = ButtonState::PRESSED;
            }
        }
    }

    void UIButton::render() {
        if (!UIComponent::isVisible())
            return;

        switch (m_state) {
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