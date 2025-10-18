#pragma once

#include <vector>
#include <stack>
#include <memory>
#include <cassert>

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
			: m_defoultSize(defoultSize)
			, m_maxSize(maxSize)
		{
			assert(m_defoultSize >= 0 && m_maxSize > 0 && m_defoultSize <= m_maxSize);
			for (int i = 0; i < m_defoultSize; ++i) {
				m_pool.push(std::make_unique<T>());
			}
		}

		virtual ~ObjectPool() = default;

		virtual std::unique_ptr<T> get() 
		{
			std::unique_ptr<T> obj;
			if (pool_.empty()) {
				obj = std::make_unique<T>();
			}
			else {
				obj = std::move(pool_.top());
				pool_.pop();
			}
			onGet(obj.get());
			return obj;
		}

		virtual void ReleaseObject(std::unique_ptr<T> obj) {
			if (!obj) return;
			onRelease(obj.get());
			if (static_cast<int>(pool_.size()) < maxSize_) {
				pool_.push(std::move(obj));
			}
			else {
				onDestroy(obj.get());
				obj.reset();
			}

		}

		virtual void onRelease(T* obj) {}
		virtual void onGet(T* obj) {}
		virtual void onDestroy(T* obj) {}
	};
}