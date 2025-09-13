
class IState {
public:
	virtual void enter() = 0;
	virtual void tick(float deltaTime) = 0;
	virtual void exit() = 0;

};