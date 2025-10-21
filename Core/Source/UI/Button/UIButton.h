#pragma once

#include "../UIComponentAnimated.h"
#include "../UILabel.h"
#include "raygui.h"
#include <functional>
#include <vector>
#include "Event/InputEvent.h"
#include "Event/EventBus.h"

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
		std::vector <EventSystem::UIEvent> m_onClick;

		ButtonState m_state = ButtonState::NORMAL;

	public:
		explicit UIButton(const Texture2D& texture, const std::string& text, const Rectangle& destRect)
			: UIComponentAnimated(texture, destRect)
			, UILabel(text, destRect)
			, m_state(ButtonState::NORMAL)
		{
		}
		~UIButton() override = default;

		bool isPressed() const noexcept { return m_state == ButtonState::PRESSED; }
		bool isHolded() const noexcept { return m_state == ButtonState::HOLDED; }

		void setState(ButtonState newState) noexcept { m_state = newState; }

		void addOnClick(const EventSystem::UIEvent& event)
		{
			m_onClick.push_back(event);
		}

		void handleEvent()
		{
			for (auto event : m_onClick)
			{
				EventSystem::EventBus<EventSystem::UIEvent>::Get().Dispatch(event);
			}
		}


		void update(float deltaTime) override;
		void render() override;

	};

}