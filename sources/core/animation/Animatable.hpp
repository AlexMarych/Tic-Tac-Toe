#pragma once

#include "animationStateMachine/AnimationStateMachine.hpp"
#include <memory>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include "core/utils/DebugUtils.hpp"

namespace Animation {

	class Animatable {

	private:
		std::unique_ptr<AnimationStateMachine> animator;
		std::unordered_map<std::string, std::shared_ptr<AnimationState>> animations;

	public:
		explicit Animatable(const Texture2D& animSheet, const Rectangle& destRect, int maxFrame)
			: animator(std::make_unique<AnimationStateMachine>())
		{
			auto idle = std::make_shared<AnimationState>(animSheet, destRect, static_cast<float>(animSheet.width), static_cast<float>(animSheet.height), maxFrame);
			addAnimation("idle", idle);
		}

		
		void addAnimation(const std::string& name, std::shared_ptr<AnimationState> animation)
		{
			animations.emplace(name, std::move(animation));
		}

		
		void play(const std::string& animationName)
		{
			if (animations.empty()) {
				throw std::runtime_error("Animatable::play: no animations available");
			}

			auto it = animations.find(animationName);
			if (it != animations.end() && it->second) {
				animator->setState(*it->second);
			} else {
				
				animator->setState(*animations.begin()->second);
				DebugUtils::println(std::string("Error: animation '") + animationName + "' does not exist");
			}
		}

		
		~Animatable() = default;
	};

} 