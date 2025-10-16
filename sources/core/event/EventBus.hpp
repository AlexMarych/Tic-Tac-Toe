#pragma once


#include <vector>
#include <algorithm>
#include <map>
#include <typeinfo>
#include "IEventListener.hpp"

namespace EventSystem
{
    template<typename T>
    class EventBus {
    private:
        EventBus() = default;
        std::vector<IEventListener*> m_Listeners;

    public:
        EventBus(const EventBus&) = delete;
        EventBus& operator=(const EventBus&) = delete;

        static EventBus& Get()
        {
            static EventBus instance;  
            return instance;
        }

        void AddListener(IEventListener* listener)
        {
            m_Listeners.push_back(listener);
        }

        void RemoveListener(IEventListener* listener)
        {
            std::erase(m_Listeners, listener);
        }

        void DispatchNow(T& e)
        {
            for (auto* listener : m_Listeners)
                listener->OnEvent(e); 
        }
    };
}