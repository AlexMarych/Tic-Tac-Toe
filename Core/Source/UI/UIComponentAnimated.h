#pragma once

#include "UIComponent.h"
#include "Animation/Animatable.h"
#include <memory>
#include <string>

namespace UI {

class UIComponentAnimated : public UIComponent, public Animation::Animatable {
public:
    explicit UIComponentAnimated(const Texture2D& texture, const Rectangle& destRect, int maxFrame = 0) noexcept;
    virtual ~UIComponentAnimated() noexcept override;

    void addAnimation(const std::string& name, Animation::AnimationState* animation);
    void addAnimation(const std::string& name, const Texture2D& sheet, const Rectangle& destRect, int maxFrame, float fps = 12.0f);

};

} 