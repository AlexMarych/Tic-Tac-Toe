#include "UIComponentAnimated.h"

namespace UI {

    UIComponentAnimated::UIComponentAnimated(const Texture2D& texture, const Rectangle& destRect, int maxFrame) noexcept
        : UIComponent(texture, destRect)
        , Animation::Animatable(texture, destRect, maxFrame)
    {
    }

    UIComponentAnimated::~UIComponentAnimated() noexcept = default;

    void UIComponentAnimated::addAnimation(const std::string& name, Animation::AnimationState* animation)
    {
        Animation::Animatable::addAnimation(name, std::move(animation));
    }

    void UIComponentAnimated::addAnimation(const std::string& name, const Texture2D& sheet, const Rectangle& destRect, int maxFrame, float fps)
    {
        auto anim = new Animation::AnimationState(sheet, destRect,
            static_cast<float>(sheet.width), static_cast<float>(sheet.height), maxFrame, fps);
        Animation::Animatable::addAnimation(name, std::move(anim));
    }

} 
