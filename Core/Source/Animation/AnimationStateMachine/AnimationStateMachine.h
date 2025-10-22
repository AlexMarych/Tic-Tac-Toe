#pragma once

#include "Patterns/State/StateMachine.h"
#include "CoreObject/Renderable.h"
#include "raylib.h"
#include <string>

namespace Animation {

    class AnimationState : public IState, public Core::Renderable {
    public:
        AnimationState() noexcept = default;
        virtual ~AnimationState() = default;

        explicit AnimationState(const Texture2D& texture, const Rectangle& destRect, float width, float height, int maxFrame, float fps = 12.0f);

        void update(float deltaTime) noexcept override;

    private:
        void updateFrame(float deltaTime);
        void render() const;

    private:
        int m_frame{ 0 };
        float m_runningTime{ 0.0f };
        float m_width{ 0.0f };
        float m_height{ 0.0f };
        int m_maxFrameCount{ 0 };
        float m_updateTime{ 1.0f / 12.0f };
    };



    class AnimationStateMachine : public StateMachine {
    public:
        AnimationStateMachine() = default;
        virtual ~AnimationStateMachine() override = default;
    };

}