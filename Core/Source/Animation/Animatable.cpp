
#include "Animatable.h"

namespace Animation {

	Animatable::Animatable(const Texture2D& animSheet, const Rectangle& destRect, int maxFrame)
		: m_animator(std::make_unique<AnimationStateMachine>())
	{
		auto idle = &AnimationState(animSheet, destRect, static_cast<float>(animSheet.width), static_cast<float>(animSheet.height), maxFrame);
		addAnimation("idle", idle);
	}

	void Animatable::addAnimation(const std::string& name, AnimationState* animation)
	{
		m_animations.emplace(name, std::move(animation));
	}

	void Animatable::play(const std::string& animationName)
	{
		if (m_animations.empty()) {
			throw std::runtime_error("Animatable::play: no animations available");
		}

		auto it = m_animations.find(animationName);
		if (it != m_animations.end() && it->second) {
			m_animator->setState(*it->second);
		}
		else {

			m_animator->setState(*m_animations.begin()->second);
			DebugUtils::println(std::string("Error: animation '") + animationName + "' does not exist");
		}
	}
}