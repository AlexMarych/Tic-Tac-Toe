#include "Layer.h"

namespace Scene
{
    Layer::Layer() = default;
    Layer::~Layer() = default;

    void Layer::OnEvent(EventSystem::Event& event)
    {
        
    }

    void Layer::update(float deltaTime)
    {
        for (const auto& obj : updateObjects) {
            if (!obj) continue;
            obj->update(deltaTime);
        }
    }

    void Layer::render()
    {
        for (const auto& obj : renderObjects) {
            if (!obj) continue; 
            obj->render();
        }
    }

    void Layer::addUpdatable(Core::IUpdatable* obj)
    {
        if (obj) updateObjects.push_back(obj);
    }

    void Layer::addRenderable(Core::IRenderable* obj)
    {
        if (obj) renderObjects.push_back(obj);
    }

    void Layer::clear() noexcept
    {
        updateObjects.clear();
        renderObjects.clear();
    }
}
