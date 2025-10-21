#pragma once

class IState
{
public:
	virtual ~IState() {};
	virtual void enter() noexcept {};
	virtual void update(float deltaTime) noexcept {};
	virtual void exit() noexcept {};

};

class StateMachine
{
private:
	IState* m_currentState = nullptr;
public:
	StateMachine() noexcept = default;
	virtual ~StateMachine() noexcept = default;

	StateMachine(const StateMachine&) = delete;
	StateMachine& operator=(const StateMachine&) = delete;

	virtual inline IState* getCurrentState() const noexcept { return m_currentState; }

	virtual void update(float deltaTime) noexcept { m_currentState->update(deltaTime); }

	virtual void setState(IState& newState) noexcept
	{
		if (m_currentState == &newState) return;

		if (m_currentState) m_currentState->exit();
		m_currentState = &newState;
		if (m_currentState) m_currentState->enter();
	}
};