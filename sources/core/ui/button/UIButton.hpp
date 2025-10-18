#pragma once

#include "../UIComponentAnimated.hpp"
#include "../UILabel.hpp"
#include "raygui.h"
#include <functional>
#include <vector>
#include "core/event/"

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
		std::vector <EventSytem::Event>> onClick;

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

		void addOnClick(std::function<void()> handler)
		{
			onClick.push_back(handler);
		}

		void handleEvent()
		{
			for each(auto func in onClick)
			{
				func();
			}
		}


		void update() override;
		void render() override;

	};

}