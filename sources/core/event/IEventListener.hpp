#pragma once

#include "Event.hpp"

namespace EventSystem
{
	class IEventListener 
	{
	public:
		virtual ~IEventListener() noexcept = default;
	 	virtual void OnEvent(Event& event) = 0;
	};
}