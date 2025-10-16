#pragma once

#include "Event.hpp"

namespace EventSystem
{
	class IEventListener 
	{
	public:
		virtual ~IEventListener() = default;
	 	virtual void OnEvent(Event& event) = 0;
	};
}