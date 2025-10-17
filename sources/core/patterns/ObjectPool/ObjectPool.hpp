#pragma once

#include <vector>
#include <stack>
#include <memory>

namespace Pool
{
	template <typename T>
	class ObjectPool {
	private:
		std::stack<std::unique_ptr<T>()> m_pool;

		int m_maxSize;
		int m_defoultSize;

	public:
		ObjectPool(int defoultSize, int maxSize)
			: m_defoultSize(defoultSize), m_maxSize(maxSize)
		{
			for (int i = 0; i < m_defoultSize; ++i) {
				m_pool.push(std::make_unique<T>());
			}
		}

		virtual ~ObjectPool() = default;

		virtual std::unique_ptr<T> Get() {
			if (m_pool.empty()) 
			{
				return std::make_unique<T>();
			}
			else
			{
				auto obj = std::move(m_pool.top());
				m_pool.pop();
				return obj;
			}
		}

		virtual void ReleaseObject(std::unique_ptr<T> obj) {
			if (m_pool.size() <= m_maxSize) 
			{
				m_pool.push(std::move(obj));
			}
			else
			{
				obj.release();
			}

		}

		virtual void OnRelease(std::unique_ptr<T> obj) {}
		virtual void OnGet(std::unique_ptr<T> obj) {}
		virtual void OnDestroy(std::unique_ptr<T> obj) {}
	};
}