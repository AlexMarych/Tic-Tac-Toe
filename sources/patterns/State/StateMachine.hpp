#include "patterns/State/IState.hpp"

class StateMachine
{
private:
	IState* currentState = nullptr;
public:
	StateMachine() = default;
	virtual ~StateMachine() = default;

	virtual inline IState* getCurrentState() const { return currentState; }

	virtual void update(float deltaTime) {};
	virtual void update() {};

	virtual void setState(IState& newState) 
	{
		if (currentState)
			currentState->exit();
		currentState = &newState;
		currentState->enter();
	}
};