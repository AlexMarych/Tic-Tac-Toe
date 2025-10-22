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
		explicit Animatable(const Texture2D& animSheet, const Rectangle& destRect, int maxFrame);

		void addAnimation(const std::string& name, AnimationState* animation);

		void play(const std::string& animationName);

		virtual ~Animatable() = default;

	private:
		std::unique_ptr<AnimationStateMachine> m_animator{};
		std::unordered_map<std::string, AnimationState*> m_animations{};
	};

} 