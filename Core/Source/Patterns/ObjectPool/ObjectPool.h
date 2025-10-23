#pragma once

#include <vector>
#include <stack>
#include <memory>
#include <cassert>

namespace Pool
{
	template <typename T>
	class ObjectPool {

	public:
		ObjectPool(int defaultSize, int maxSize)
			: m_defaultSize(defaultSize)
			, m_maxSize(maxSize)
		{
			assert(m_defoultSize >= 0 &&
				m_maxSize > 0 &&
				m_defoultSize <= m_maxSize);

			for (int i = 0; i < m_defoultSize; ++i) {
				m_pool.push(std::make_unique<T>());
			}
		}

		virtual ~ObjectPool() = default;

		T* get() 
		{
			std::unique_ptr<T> obj;
			if (m_pool.empty()) {
				obj = std::make_unique<T>();
			}
			else {
				obj = std::move(m_pool.top());
				m_pool.pop();
			}
			onGet(obj.get());
			return obj;
		}

		virtual void ReleaseObject(std::unique_ptr<T> obj) {
			if (!obj) return;

			onRelease(obj.get());

			const bool hasSpace = static_cast<int>(m_pool.size()) < m_maxSize;
			
			if (hasSpace) {
				m_pool.push(std::move(obj));
			}
			else {
				onDestroy(obj.get());
				obj.reset();
			}

		}

		virtual void onRelease(T* obj) noexcept{}
		virtual void onGet(T* obj) noexcept {}
		virtual void onDestroy(T* obj) noexcept {}

	private:
		std::stack<std::unique_ptr<T>> m_pool{};

		int m_maxSize{};
		int m_defoultSize{};
	};
}