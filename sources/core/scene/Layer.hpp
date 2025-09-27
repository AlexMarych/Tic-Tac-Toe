#pragma once

#include <vector>
#include <memory>

namespace Scene {

	class Layer
	{
	private:
		int depth;
		std::vector<std::shared_ptr<Core::Renderable>> renderObjects;
		std::vector<std::shared_ptr<Core::IUpdatable>> updateObjects;

		bool operator<(const Layer& other) const {
			return depth < other.depth;
		}
	public:
		Layer(int d) : depth(d) {}
		~Layer() = default;

		void tick(float deltaTime) {
			for (auto obj : updateObjects) {
				obj->update(deltaTime);
			}

			for (auto obj : renderObjects) {
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
	};

}