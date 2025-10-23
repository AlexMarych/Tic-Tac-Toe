
#include "AnimationStateMachine.h"

namespace Animation {

    AnimationState::AnimationState(const Texture2D& texture, const Rectangle& destRect, float width, float height, int maxFrame, float fps)
        : Renderable(texture, destRect),
        m_frame(0),
        m_runningTime(0.0f),
        m_width(width),
        m_height(height),
        m_maxFrameCount(maxFrame),
        m_updateTime((fps > 0.0f) ? (1.0f / fps) : 1.0f / 12.0f)
    {
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
        Rectangle source{
            static_cast<float>(m_frame) * m_width,
            0.0f,
            m_width,
            m_height
        };
        DrawTexturePro(getTexture(), source, getPosition(), getOrigin(), getRotation(), getTint());
    }


}