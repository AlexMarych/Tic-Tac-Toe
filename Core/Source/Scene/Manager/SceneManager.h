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
        SceneManager();
        ~SceneManager();

        SceneManager(const SceneManager&) = delete;
        SceneManager& operator=(const SceneManager&) = delete;
        SceneManager(SceneManager&&) noexcept = default;
        SceneManager& operator=(SceneManager&&) noexcept = default;

        void update(float deltaTime) override;
        void render() override;

        template<typename TLayer, typename... Args>
        void pushLayer(Args&&... args)
        {
            static_assert(std::is_base_of_v<Layer, TLayer>, "TLayer must derive from Scene::Layer");
            auto layer = std::make_unique<TLayer>(std::forward<Args>(args)...);
            m_layerStack.push_back(std::move(layer));
        }

        void clearLayers() noexcept;

		inline std::size_t getLayerCount() const noexcept { return m_layerStack.size(); }


	private:
		std::vector<std::unique_ptr<Layer>> m_layerStack;
	};

}