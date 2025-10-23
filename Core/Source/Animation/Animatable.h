#pragma once

#include "animationStateMachine/AnimationStateMachine.h"
#include <memory>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include "Utils/DebugUtils.h"
#include "CoreObject/IUpdatable.h"

namespace Animation {

	class Animatable : public virtual Core::IUpdatable {

	public:
		explicit Animatable(const Texture2D& animSheet, const Rectangle& destRect, int maxFrame = 1);

		void addAnimation(const std::string& name, std::unique_ptr<AnimationState> animation);
		void addAnimation(const std::string& name, const Texture2D& sheet, const Rectangle& destRect, int maxFrame, float fps);


		void play(const std::string& animationName);

		virtual ~Animatable() = default;

		void update(float deltaTime) override;

	private:
		std::unique_ptr<StateMachine<AnimationState>> m_animator{};
		std::unordered_map<std::string, std::unique_ptr<AnimationState>> m_animations{};
		std::string m_currentAnimation{};
	};

} 