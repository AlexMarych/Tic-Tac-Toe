#pragma once

#include "CoreObject/IUpdatable.h"
#include <memory>

class IState
{
public:
	virtual ~IState() {};
	virtual void enter() noexcept {};
	virtual void update(float deltaTime) noexcept {};
	virtual void exit() noexcept {};

};

template <typename StateType>
class StateMachine {
    static_assert(std::is_base_of<IState, StateType>::value, "StateType must derive from IState");

public:
    StateMachine() noexcept = default;
    ~StateMachine() noexcept = default;

    StateMachine(const StateMachine&) = delete;
    StateMachine& operator=(const StateMachine&) = delete;

    void setState(StateType* newState) noexcept {
		if (m_currentState) m_currentState->exit();
        m_currentState = newState;
        if (m_currentState) m_currentState->enter();
    }

    StateType* getCurrentState() const noexcept {
        return m_currentState;
    }

    void update(float deltaTime) noexcept {
        if (m_currentState) {
            m_currentState->update(deltaTime);
        }
    }

private:
    StateType* m_currentState;
};