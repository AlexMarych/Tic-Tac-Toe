#pragma once

#include <vector>
#include <memory>
#include <type_traits>
#include "Patterns/State/StateMachine.hpp"
#include "Scene/Layer.hpp"
#include "CoreObject/IRenderable.hpp"
#include "CoreObject/IUpdatable.hpp"

using Layer = Scene::Layer;

namespace Scene {

	class SceneManager : public Core::IUpdatable, public Core::IRenderable{
	private:
		std::vector<std::unique_ptr<Layer>> layerStack;

	public:
		SceneManager() {}
		~SceneManager() {}

		SceneManager(const SceneManager&) = delete;
		SceneManager& operator=(const SceneManager&) = delete;
		SceneManager(SceneManager&&) noexcept = default;
		SceneManager& operator=(SceneManager&&) noexcept = default;

		void update(float deltaTime) override
		{
			for (const auto& layer : layerStack) 
			{
				if(layer) layer->update(deltaTime);
			}
		}

		void render() override
		{
			for (const auto& layer : layerStack)
			{
				if (layer) layer->render();
			}
		}

		template<typename TLayer, typename... Args>
		void pushLayer(Args&&... args)
		{
			static_assert(std::is_base_of_v<Layer, TLayer>, "TLayer must derive from Scene::Layer");
			layerStack.push_back(std::make_unique<TLayer>(std::forward<Args>(args)...));
		}

		std::size_t getLayerCount() const noexcept { return layerStack.size(); }

		void clearLayers() noexcept { layerStack.clear(); }
	};

}