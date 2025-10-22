#include "UIComponent.h"

namespace UI {

    bool UIComponent::s_guiSliderDragging = false;

    UIComponent::UIComponent(const Texture2D& texture, const Rectangle& destRect) noexcept
        : Core::GameObject(texture, std::string(), destRect)
        , m_visible(true)
    {
    }

    UIComponent::~UIComponent() noexcept = default;


    bool UIComponent::isInBounds(Vector2& point)
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
