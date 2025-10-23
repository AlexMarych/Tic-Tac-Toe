#pragma once

#include "UI/UILabel.h"
#include "UI/UIComponent.h"
#include "Animation/Animatable.h"
#include <raygui.h>
#include <raylib.h>
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

	class UIButton : public UIComponent, public UILabel, public Animation::Animatable
	{
	public:
		explicit UIButton(const Texture2D& texture, const std::string& text, const Rectangle& destRect, const RectangleOffset& offset) noexcept;
		virtual ~UIButton() override = default;

		inline bool isPressed() const noexcept { return m_state == ButtonState::PRESSED; }
		inline bool isHolded() const noexcept { return m_state == ButtonState::HOLDED; }

		inline void setOffset(const RectangleOffset& offset) noexcept { m_textOffset = offset; }
		inline const RectangleOffset& getOffset() const noexcept { return m_textOffset; }

		inline void setState(ButtonState newState) noexcept { m_state = newState; }

		void addOnClick(const EventSystem::UIEvent& event);

		void handleEvent();
		void update(float deltaTime) override;
		void render() override;

	private:
		std::vector <EventSystem::UIEvent> m_onClick{};
		RectangleOffset m_textOffset{0,0};
		ButtonState m_state = ButtonState::NORMAL;
	};

}