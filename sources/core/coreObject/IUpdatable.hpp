#pragma once

#include "Renderable.hpp"

namespace Core {

	class IUpdatable {

	public:
		virtual ~IUpdatable() = 0;
		virtual void update(float deltaTime) = 0;
		virtual void update() = 0;

	};

}