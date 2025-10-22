#include "SceneManager.h"

namespace Scene {

    SceneManager::SceneManager() = default;

    SceneManager::~SceneManager() = default;

    void SceneManager::update(float deltaTime)
    {
        for (const auto& layer : m_layerStack) {
            if (layer) layer->update(deltaTime);
        }
    }

    void SceneManager::render()
    {
        for (const auto& layer : m_layerStack) {
            if (layer) layer->render();
        }
    }


    void SceneManager::clearLayers() noexcept
    {
        m_layerStack.clear();
    }

} 
