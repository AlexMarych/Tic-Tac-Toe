#include "StateMachine.h"

StateMachine::~StateMachine() noexcept = default;

void StateMachine::update(float deltaTime) noexcept
{
    if (m_currentState)
        m_currentState->update(deltaTime);
}

void StateMachine::setState(IState& newState) noexcept
{
    if (m_currentState == &newState) return;

    if (m_currentState)
        m_currentState->exit();

    m_currentState = &newState;

    if (m_currentState)
        m_currentState->enter();
}
