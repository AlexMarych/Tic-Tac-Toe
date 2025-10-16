#pragma once

#include <vector>
#include <memory>
#include "core/patterns/State/StateMachine.hpp"
#include "core/scene/Layer.hpp"
#include "core/coreObject/IRenderable.hpp"
#include "core/coreObject/IUpdatable.hpp"

using Layer = Scene::Layer;

namespace Scene {

	class SceneManager : public Core::IUpdatable, public Core::IRenderable{
	private:
		std::vector<std::unique_ptr<Layer>> layerStack;

	public:
		SceneManager() {}
		virtual ~SceneManager() {}

		void update(float deltaTime) override
		{
			for (const auto& layer : layerStack) {
				layer->update(deltaTime);
				
			}
		}

		void render() override
		{
			for (const auto& layer : layerStack)
			{
				layer->render();
			}
		}

		template<typename TLayer>
		void PushLayer()
		{
			static_assert(std::is_base_of_v<Layer, TLayer>,
				"TLayer must derive from Layer");

			layerStack.push_back(std::make_unique<TLayer>());
		}
	};

}