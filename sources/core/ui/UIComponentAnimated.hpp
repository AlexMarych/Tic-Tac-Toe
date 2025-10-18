#pragma once

#include "UIComponent.hpp"
#include "../animation/Animatable.hpp"
#include <memory>
#include <string>

namespace UI {

class UIComponentAnimated : public UIComponent, public Animation::Animatable {
public:
    explicit UIComponentAnimated(const Texture2D& texture, const Rectangle& destRect, int maxFrame = 0) noexcept
        : UIComponent(texture, destRect)
        , Animation::Animatable(texture, destRect, maxFrame)
    {
    }

    ~UIComponentAnimated() noexcept = default;

    void addAnimation(const std::string& name, std::shared_ptr<Animation::AnimationState> animation)
    {
        Animation::Animatable::addAnimation(name, std::move(animation));
    }

    void addAnimation(const std::string& name, const Texture2D& sheet, const Rectangle& destRect, int maxFrame, float fps = 12.0f)
    {
        auto anim = std::make_shared<Animation::AnimationState>(sheet, destRect,
            static_cast<float>(sheet.width), static_cast<float>(sheet.height), maxFrame, fps);
        Animation::Animatable::addAnimation(name, std::move(anim));
    }
};

} 