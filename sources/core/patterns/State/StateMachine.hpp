#pragma once

class IState
{
public:
	virtual ~IState() {};
	virtual void enter() {};
	virtual void tick(float deltaTime) {};
	virtual void tick() {};
	virtual void exit() {};

};

class StateMachine
{
private:
	IState* currentState = nullptr;
public:
	StateMachine() = default;
	virtual ~StateMachine() = default;

	virtual inline IState* getCurrentState() const { return currentState; }

	virtual void update(float deltaTime) { currentState->tick(deltaTime); }
	virtual void update() { currentState->tick(); }

	virtual void setState(IState& newState) 
	{
		if (currentState)
			currentState->exit();
		currentState = &newState;
		currentState->enter();
	}
};