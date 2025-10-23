#pragma once

namespace Core {

	class IUpdatable {
	public:
		virtual ~IUpdatable() noexcept = default;
		virtual void update(float deltaTime) = 0;
	};

}