#pragma once


namespace Core {

	class IRenderable {
	public:
		virtual ~IRenderable() = default;
		virtual void render() = 0;
	};
}