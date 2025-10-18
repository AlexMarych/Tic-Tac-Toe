#pragma once


namespace Core {

	class IRenderable {
	public:
		virtual ~IRenderable() noexcept = default;
		virtual void render() = 0;
	};
}