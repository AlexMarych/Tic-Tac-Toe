#pragma once

#include "animationStateMachine/AnimationStateMachine.hpp"
#include <map>
#include <string>
#include "../../../utils/DebugUtils.hpp"

class Animatable {

private:

	AnimationStateMachine* animator;
	std::map<std::string, AnimationState> animations;

public:
	Animatable() 
	{ 
		animator = new AnimationStateMachine();
	}

	void addAnimation(std::string name, const AnimationState& animation)
	{
		animations[name] = animation;
	}

	void Play(std::string animationName)
	{
		if (!animations.empty()) {
			if ((animations.find(animationName)) != animations.end()) {
				animator->setState(animations[animationName]);
			}
			else 
			{
				animator->setState(animations.begin()->second);
				DebugUtils::println("Error " + animationName + " does not exist");
			}
		}
		else
		{
			throw 404;
		}
		
	}

};