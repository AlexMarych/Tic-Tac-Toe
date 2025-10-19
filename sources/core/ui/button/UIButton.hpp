#pragma once

#include "../UIComponentAnimated.hpp"
#include "../UILabel.hpp"
#include "raygui.h"
#include <functional>
#include <vector>
#include "core/event/InputEvent.hpp"
#include "core/event/EventBus.hpp"

namespace UI {

	enum class ButtonState {
		NORMAL = 0,
		FOCUSED,
		PRESSED,
		HOLDED,
		DISABLED
	};

	class UIButton : public UIComponentAnimated, public UILabel
	{
	private:
		std::vector <EventSystem::UIEvent> onClick;

		ButtonState state = ButtonState::NORMAL;

	public:
		explicit UIButton(const Texture2D& texture, const std::string& text, const Rectangle& destRect)
			: UIComponentAnimated(texture, destRect)
			, UILabel(text, destRect)
			, state(ButtonState::NORMAL)
		{
		}
		~UIButton() override = default;

		bool isPressed() const noexcept { return state == ButtonState::PRESSED; }
		bool isHolded() const noexcept { return state == ButtonState::HOLDED; }

		void setState(ButtonState newState) noexcept { state = newState; }

		void addOnClick(const EventSystem::UIEvent& event)
		{
			onClick.push_back(event);
		}

		void handleEvent()
		{
			for (auto event : onClick)
			{
				EventSystem::EventBus<EventSystem::UIEvent>::Get().Dispatch(event);
			}
		}


		void update() override;
		void render() override;

	};

}