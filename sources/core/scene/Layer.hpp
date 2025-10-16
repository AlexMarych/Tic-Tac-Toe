#pragma once

#include <vector>
#include <memory>
#include "core/coreObject/IUpdatable.hpp"
#include "core/coreObject/IRenderable.hpp"
#include "core/event/IEventListener.hpp"
#include "core/patterns/Factory/IProduct.hpp"


namespace Scene 
{
	class Layer : public Core::IUpdatable, public Core::IRenderable, public EventSystem::IEventListener, public Factory::IProduct
	{
	private:
		
		std::vector<std::shared_ptr<Core::IRenderable>> renderObjects;
		std::vector<std::shared_ptr<Core::IUpdatable>> updateObjects;

		
	public:
		Layer() = default;
		virtual ~Layer() = default;

		virtual void OnEvent(EventSystem::Event& event) override {}

		virtual void update(float deltaTime) override
		{
			for (const auto& obj : updateObjects) {
				obj->update(deltaTime);
			}
		}

		virtual void render() override
		{
			for (const auto& obj : renderObjects) {
				obj->render();
			}
		}

		template <typename T>
		void addObject(const std::shared_ptr<T>& obj) {
			if (auto u = std::dynamic_pointer_cast<IUpdatable>(obj)) {
				updateObjects.push_back(u);
			}
			if (auto r = std::dynamic_pointer_cast<Renderable>(obj)) {
				renderObjects.push_back(r);
			}
		}

		virtual void LoadFromJson(const nlohmann::json& data) override
		{
			// an example
			/*if (data.contains("objects")) {

				if (data["properties"].contains("text")) {
					text = data["properties"]["text"].get<std::string>();
				}
			}*/
		}

		virtual nlohmann::json LoadToJson() override
		{
			// an example
			/*std::map<std::string, nlohmann::json> properties;

			properties["text"] = text;

			nlohmann::json j = getJsonTemplate();
			j["type"] = getClassName();
			j["properties"] = properties;
			return j;*/
		}
	};

}