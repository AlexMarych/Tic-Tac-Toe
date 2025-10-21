#pragma once

#include "Event.h"

namespace EventSystem
{
	class IEventListener 
	{
	public:
		virtual ~IEventListener() noexcept = default;
	 	virtual void OnEvent(Event& event) = 0;
	};
}