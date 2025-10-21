#pragma once

#include <vector>
#include <memory>
#include <type_traits>
#include "Patterns/State/StateMachine.h"
#include "Scene/Layer.h"
#include "CoreObject/IRenderable.h"
#include "CoreObject/IUpdatable.h"

using Layer = Scene::Layer;

namespace Scene {

	class SceneManager : public Core::IUpdatable, public Core::IRenderable{

	public:
		SceneManager() {}
		~SceneManager() {}

		SceneManager(const SceneManager&) = delete;
		SceneManager& operator=(const SceneManager&) = delete;
		SceneManager(SceneManager&&) noexcept = default;
		SceneManager& operator=(SceneManager&&) noexcept = default;

		void update(float deltaTime) override
		{
			for (const auto& layer : m_layerStack) 
			{
				if(layer) layer->update(deltaTime);
			}
		}

		void render() override
		{
			for (const auto& layer : m_layerStack)
			{
				if (layer) layer->render();
			}
		}

		template<typename TLayer, typename... Args>
		void pushLayer(Args&&... args)
		{
			static_assert(std::is_base_of_v<Layer, TLayer>, "TLayer must derive from Scene::Layer");
			m_layerStack.push_back(std::make_unique<TLayer>(std::forward<Args>(args)...));
		}

		std::size_t getLayerCount() const noexcept { return m_layerStack.size(); }

		void clearLayers() noexcept { m_layerStack.clear(); }

	private:
		std::vector<std::unique_ptr<Layer>> m_layerStack;
	};

}