#pragma once

#include <string>

namespace EventSystem {

    class Event {
    private:
        std::string name;
        bool Handled = false;
    public:
        explicit Event(const std::string& name) : name(name) {}
        Event(const Event&) = default;
        Event(Event&&) noexcept = default;

        Event& operator=(const Event&) = default;
        Event& operator=(Event&&) noexcept = default;

        virtual ~Event() noexcept = default;

        const std::string& getName() const noexcept { return name; }

    };

}