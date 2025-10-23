
#include "AnimationStateMachine.h"

namespace Animation {

    constexpr int DEFAULT_FPS = (1.0f / 12.0f);

    AnimationState::AnimationState(const Texture2D& texture, const Rectangle& destRect, float width, float height, int maxFrame, float fps)
        : Renderable(texture, destRect),
        m_frame(0),
        m_runningTime(0.0f),
        m_width(width),
        m_height(height),
        m_maxFrameCount(maxFrame)
    {
        auto effectiveFPS = (fps > 0.0f) ? fps : DEFAULT_FPS;
        m_updateTime = 1.0f / effectiveFPS;
    }

    void AnimationState::update(float deltaTime) noexcept {
        updateFrame(deltaTime);
		render();
	}

    void AnimationState::updateFrame(float deltaTime) {
        m_runningTime += deltaTime;
        if (m_runningTime >= m_updateTime) {
            ++m_frame;
            m_runningTime = 0.0f;
            if (m_frame > m_maxFrameCount)
                m_frame = 0;
        }
    }

    void AnimationState::render() {
        auto currentTexturePos = m_frame * m_width;

        this->setSourceRect({
            currentTexturePos,
            m_origin,
            m_width,
            m_height
        });
		Renderable::render();
    }


}