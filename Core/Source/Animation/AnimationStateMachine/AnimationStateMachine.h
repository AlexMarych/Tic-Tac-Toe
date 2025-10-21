#pragma once

#include "Patterns/State/StateMachine.h"
#include "CoreObject/Renderable.h"
#include "raylib.h"
#include <string>

namespace Animation {

    class AnimationState : public IState, public Core::Renderable {
    public:
        AnimationState() noexcept = default;

        explicit AnimationState(const Texture2D& texture,
            const Rectangle& destRect,
            float width,
            float height,
            int maxFrame,
            float fps = 12.0f)
            : Renderable(texture, destRect)
            , m_frame(0)
            , m_runningTime(0.0f)
            , m_width(width)
            , m_height(height)
            , m_maxFrameCount(maxFrame)
            , m_updateTime((fps > 0.0f) ? (1.0f / fps) : 1.0f / 12.0f)
        {
        }


        void update(float deltaTime) noexcept override
        {
            updateFrame(deltaTime);
            render();
        }


        void updateFrame(float deltaTime)
        {
            m_runningTime += deltaTime;
            if (m_runningTime >= m_updateTime) {
                ++m_frame;
                m_runningTime = 0.0f;
                if (m_frame > m_maxFrameCount) m_frame = 0;
            }
        }


        void render() const
        {
            Rectangle source{
                static_cast<float>(m_frame) * m_width,
                0.0f,
                m_width,
                m_height
            };
            DrawTexturePro(getTexture(), source, getPosition(), getOrigin(), getRotation(), getTint());
        }

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
        ~AnimationStateMachine() override = default;


    };

}