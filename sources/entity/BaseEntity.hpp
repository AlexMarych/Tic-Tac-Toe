#include "raylib.h"
#include "GameObject.hpp"
#include <map>

enum AnimationState {
	IDLE,
	AIRBORN
};

class BaseEntity : GameObject{
	public:
		BaseEntity(const Texture2D& texture)
		virtual ~BaseEntity() = default;
		virtual void update(float deltaTime) = 0;

	protected:
		const Texture2D texture;
		AnimationState currentState;
		std::map<AnimationState, Texture2D> animations;
		
}