#pragma once

#include "animationStateMachine/AnimationStateMachine.h"
#include <memory>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include "Utils/DebugUtils.h"

namespace Animation {

	class Animatable {

	public:
		explicit Animatable(const Texture2D& animSheet, const Rectangle& destRect, int maxFrame)
			: m_animator(std::make_unique<AnimationStateMachine>())
		{
			auto idle = &AnimationState(animSheet, destRect, static_cast<float>(animSheet.width), static_cast<float>(animSheet.height), maxFrame);
			addAnimation("idle", idle);
		}

		
		void addAnimation(const std::string& name, AnimationState* animation)
		{
			m_animations.emplace(name, std::move(animation));
		}

		
		void play(const std::string& animationName)
		{
			if (m_animations.empty()) {
				throw std::runtime_error("Animatable::play: no animations available");
			}

			auto it = m_animations.find(animationName);
			if (it != m_animations.end() && it->second) {
				m_animator->setState(*it->second);
			} else {
				
				m_animator->setState(*m_animations.begin()->second);
				DebugUtils::println(std::string("Error: animation '") + animationName + "' does not exist");
			}
		}

		
		~Animatable() = default;

	private:
		std::unique_ptr<AnimationStateMachine> m_animator{};
		std::unordered_map<std::string, AnimationState*> m_animations{};
	};

} 