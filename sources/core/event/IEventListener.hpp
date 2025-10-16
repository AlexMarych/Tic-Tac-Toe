#pragma once

#include "Event.hpp"

namespace Event
{
	class IEventListener 
	{
	public:
		virtual ~IEventListener() = default;
	 	virtual void OnEvent(Event& event) = 0;
	};
}