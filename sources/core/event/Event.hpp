#pragma once

#include <string>

namespace EventSystem {

	class Event
	{
	private:
		std::string name;
	public:
		
		Event(const std::string& name) : name(name) {}
		virtual ~Event() = default;
		std::string getName() const { return name; }
	};

}