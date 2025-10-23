#include "UIComponent.h"

namespace UI {

    bool UIComponent::s_guiSliderDragging = false;

    UIComponent::UIComponent(const Texture2D& texture, const std::string& text, const Rectangle& destRect) noexcept
        : GameObject(texture, text, destRect)
        , m_visible(true)
    {
    }

    UIComponent::~UIComponent() noexcept = default;


    bool UIComponent::isInBounds(const Vector2& point) const
    {
        return CheckCollisionPointRec(point, m_bounds);
    }

    void UIComponent::update(float deltaTime)
    {
        GameObject::update(deltaTime);
    }

    void UIComponent::render()
    {
        Renderable::render();
    }

} 
