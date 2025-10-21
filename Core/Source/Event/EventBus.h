#pragma once


#include <vector>
#include <algorithm>
#include <map>
#include <typeinfo>
#include "IEventListener.h"

namespace EventSystem
{
    template<typename T>
    class EventBus {

    public:
        EventBus(const EventBus&) = delete;
        EventBus& operator=(const EventBus&) = delete;
        EventBus(EventBus&&) = delete;
        EventBus& operator=(EventBus&&) = delete;

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

        void Dispatch(T& e)
        {
            for (auto* listener : m_Listeners)
                listener->OnEvent(e); 
        }

    private:
        EventBus() = default;
        std::vector<IEventListener*> m_Listeners;
    };
}