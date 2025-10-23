
#include "Animatable.h"

namespace Animation {

	Animatable::Animatable(const Texture2D& animSheet, const Rectangle& destRect, int maxFrame)
		: m_animator(std::make_unique<StateMachine<AnimationState>>())
	{
		auto idle = std::make_unique<AnimationState>(animSheet, destRect,
			static_cast<float>(animSheet.width),
			static_cast<float>(animSheet.height),
			maxFrame); 
		addAnimation("idle", std::move(idle));
		play("idle");
	}

	void Animatable::addAnimation(const std::string& name, std::unique_ptr<AnimationState> animation)
	{
		m_animations.emplace(name, std::move(animation));
	}

	void Animatable::addAnimation(const std::string& name, const Texture2D& sheet, const Rectangle& destRect, int maxFrame, float fps)
	{
		auto anim = std::make_unique<AnimationState>(sheet, destRect,
			static_cast<float>(sheet.width), static_cast<float>(sheet.height), maxFrame, fps);
		addAnimation(name, std::move(anim));
	}

	void Animatable::play(const std::string& animationName)
	{
		if (m_currentAnimation == animationName) return;

		if (m_animations.empty()) {
			throw std::runtime_error("Animatable::play: no animations available");
		}

		auto it = m_animations.find(animationName);
		if (it != m_animations.end() && it->second) {
			m_animator->setState(std::move(it->second));
			m_currentAnimation = it->first;
		}
		else {

			m_animator->setState(move(m_animations.begin()->second));
			m_currentAnimation = m_animations.begin()->first;
			DebugUtils::println(std::string("Error: animation '") + animationName + "' does not exist");
		}
	}

	void Animatable::update(float deltaTime)
	{
		if (m_animator) {
			m_animator->update(deltaTime);
		}
	}
}