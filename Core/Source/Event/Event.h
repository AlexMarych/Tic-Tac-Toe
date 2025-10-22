#pragma once

#include <string>

namespace EventSystem {

    class Event {
    
    public:
        explicit Event(const std::string& name) : m_name(name) {}
        Event(const Event&) = default;
        Event(Event&&) noexcept = default;

        Event& operator=(const Event&) = default;
        Event& operator=(Event&&) noexcept = default;

        virtual ~Event() noexcept = default;

        inline const std::string& getName() const noexcept { return m_name; }
        inline bool isHandled() const noexcept { return m_handled; }

    private:
        std::string m_name{};
        bool m_handled{ false };
    };


}