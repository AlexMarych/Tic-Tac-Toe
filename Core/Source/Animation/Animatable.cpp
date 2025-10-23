
#include "Animatable.h"

namespace Animation {

	constexpr int DEFAULT_FPS = 12.0f;

	Animatable::Animatable(const Texture2D& animSheet, const Rectangle& destRect, int maxFrame)
		: m_animator(std::make_unique<StateMachine<AnimationState>>())
	{
		auto width = static_cast<float>(animSheet.width);
		auto height = static_cast<float>(animSheet.height);

		auto idle = std::make_unique<AnimationState>(
			animSheet,
			destRect,
			width,
			height,
			maxFrame,
			DEFAULT_FPS
		); 
		addAnimation("idle", std::move(idle));

		play("idle");
	}

	void Animatable::addAnimation(const std::string& name, std::unique_ptr<AnimationState> animation)
	{
		m_animations.emplace(name, 	std::move(animation));
	}

	void Animatable::addAnimation(const std::string& name, const Texture2D& sheet, const Rectangle& destRect, int maxFrame, float fps)
	{
		auto width = static_cast<float>(sheet.width);
		auto height = static_cast<float>(sheet.height);

		auto anim = std::make_unique<AnimationState>(sheet, destRect,width,height,maxFrame, fps);

		addAnimation(name, std::move(anim));
	}

	void Animatable::play(const std::string& animationName)
	{
		if (m_currentAnimation == animationName) return;

		if (m_animations.empty()) {
			throw std::runtime_error("Animatable::play: no animations available");
		}

		const auto& it = m_animations.find(animationName);
		if (it != m_animations.end() && it->second) {

			m_animator->setState(	std::move(it->second));

			m_currentAnimation = it->first;
		}
		else {

			auto it = m_animations.begin();

			m_animator->setState(std::move(it->second));
			m_currentAnimation = it->first;
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