#pragma once

#include <vector>
#include <memory>
#include "CoreObject/IUpdatable.h"
#include "CoreObject/IRenderable.h"
#include "Event/IEventListener.h"
#include "Patterns/Factory/IProduct.h"


namespace Scene 
{
	class Layer : public Core::IUpdatable, public Core::IRenderable, public EventSystem::IEventListener, public Factory::IProduct
	{
		
	public:
		Layer() = default;
		virtual ~Layer() = default;

		virtual void OnEvent(EventSystem::Event& event) override {}

		virtual void update(float deltaTime) override
		{
			for (const auto& obj : updateObjects) 
			{
				if (obj) obj->update(deltaTime);
			}
		}

		virtual void render() override
		{
			for (const auto& obj : renderObjects) 
			{
				if (obj) obj->render();
			}
		}

		template <typename T>
		void addObject(T* obj) {

			static_assert(std::is_base_of<Core::IUpdatable, T>::value || std::is_base_of<Core::IRenderable, T>::value,
				"Type T must derive from IUpdatable or IRenderable");

			if (!obj) return;

			if (auto u = dynamic_cast<Core::IUpdatable*>(obj)) {
				updateObjects.push_back(u);
			}
			if (auto r = dynamic_cast<Core::IRenderable*>(obj)) {
				renderObjects.push_back(r);
			}
		}

		void addUpdatable(Core::IUpdatable* obj)
		{
			if (obj) updateObjects.push_back(obj);
		}

		void addRenderable(Core::IRenderable* obj)
		{
			if (obj) renderObjects.push_back(obj);
		}

		template <typename T>
		void removeObject(const T* obj)
		{
			if (!obj) return;
			renderObjects.erase(std::remove(renderObjects.begin(), renderObjects.end(), obj), renderObjects.end());
			updateObjects.erase(std::remove(updateObjects.begin(), updateObjects.end(), obj), updateObjects.end());
		}
		
		void clear() noexcept
		{
			updateObjects.clear();
			renderObjects.clear();
		}

	private:
		std::vector<Core::IRenderable*> renderObjects;
		std::vector<Core::IUpdatable*> updateObjects;
	};

}