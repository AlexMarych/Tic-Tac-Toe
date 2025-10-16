#pragma once

#include "Renderable.hpp"

namespace Core {

	class IUpdatable {
	public:
		virtual ~IUpdatable() = default;
		virtual void update(float deltaTime) = 0;
	};

}