#pragma once

#include "Patterns/State/StateMachine.hpp"
#include "CoreObject/Renderable.hpp"
#include "raylib.h"
#include <string>

namespace Animation {

class AnimationState : public IState, public Core::Renderable {
private:
    int frame{0};
    float runningTime{0.0f};          
    float width{0.0f};
    float height{0.0f};
    int maxFrameCount{0};             
    float updateTime{1.0f / 12.0f};   

public:
    AnimationState() noexcept = default;

    explicit AnimationState(const Texture2D& texture,
                            const Rectangle& destRect,
                            float width,
                            float height,
                            int maxFrame,
                            float fps = 12.0f)
        : Renderable(texture, destRect)
        , frame(0)
        , runningTime(0.0f)
        , width(width)
        , height(height)
        , maxFrameCount(maxFrame)
        , updateTime((fps > 0.0f) ? (1.0f / fps) : 1.0f / 12.0f)
    {
    }

    
    void update(float deltaTime) noexcept override
    { 
        updateFrame(deltaTime);
        render();
    }


    void updateFrame(float deltaTime)
    {
        runningTime += deltaTime;
        if (runningTime >= updateTime) {
            ++frame;
            runningTime = 0.0f;
            if (frame > maxFrameCount) frame = 0;
        }
    }

    
    void render() const
    {
        Rectangle source{
            static_cast<float>(frame) * width,
            0.0f, 
            width,
            height
        };
        DrawTexturePro(getTexture(), source, getPosition(), getOrigin(), getRotation(), getTint());
    }

};

class AnimationStateMachine : public StateMachine {
public:
    AnimationStateMachine() = default;
    ~AnimationStateMachine() override = default;

    
};

} 