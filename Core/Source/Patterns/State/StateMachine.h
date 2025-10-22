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
public:
	StateMachine() noexcept = default;
	virtual ~StateMachine() noexcept;

	StateMachine(const StateMachine&) = delete;
	StateMachine& operator=(const StateMachine&) = delete;

	inline virtual IState* getCurrentState() const noexcept { return m_currentState; }
	virtual void update(float deltaTime) noexcept;
	virtual void setState(IState& newState) noexcept;

private:
	IState* m_currentState{};
};