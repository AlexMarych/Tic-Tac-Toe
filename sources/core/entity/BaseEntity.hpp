#pragma once

#include "raylib.h"
#include <string>
#include "../core/coreObject/GameObject.hpp"
#include "../core/animation/Animatable.hpp"

namespace Core 
{

    class BaseEntity : public GameObject, public Animation::Animatable {
    public:
        BaseEntity() noexcept = default;

        BaseEntity(const Texture2D& texture, const std::string& name, const Rectangle& destRect, int maxFrame)
            : GameObject(texture, name, destRect)
            , Animation::Animatable(texture, destRect, maxFrame)
        {
        }

        ~BaseEntity() noexcept override = default;

        BaseEntity(const BaseEntity&) = default;
        BaseEntity& operator=(const BaseEntity&) = default;
        BaseEntity(BaseEntity&&) noexcept = default;
        BaseEntity& operator=(BaseEntity&&) noexcept = default;
    };

}