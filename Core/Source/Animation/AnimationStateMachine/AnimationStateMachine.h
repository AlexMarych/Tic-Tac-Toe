#pragma once

#include "Patterns/State/StateMachine.h"
#include "CoreObject/Renderable.h"
#include "raylib.h"
#include <string>

namespace Animation {

    class AnimationState : public IState, public virtual Core::Renderable {
    public:
        AnimationState() noexcept = default;
        virtual ~AnimationState() = default;

        explicit AnimationState(const Texture2D& texture, const Rectangle& destRect, float width, float height, int maxFrame, float fps);

        void update(float deltaTime) noexcept override;

        void render() override;

    private:
        void updateFrame(float deltaTime);

    private:
        int m_frame{ 0 };
        float m_runningTime{ 0.0f };
        float m_width{ 0.0f };
        float m_origin{ 0.0f };
        float m_height{ 0.0f };
        int m_maxFrameCount{ 0 };
        float m_updateTime{ 1.0f / 12.0f };
    };

}