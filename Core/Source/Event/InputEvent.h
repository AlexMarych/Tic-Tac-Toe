#pragma once

#include "Event.h"

namespace EventSystem
{

    enum class MouseAction
    {
        Pressed,
        Released,
        Repeated,
        Moved
    };

    enum class KeyAction
    {
        Pressed,
        Released,
        Repeated
    };

    class InputEvent : public Event {
    public:
        InputEvent(const std::string& name) : Event(name) {};
        virtual ~InputEvent() = default;
    };


    class UIEvent : public InputEvent
    {

	public:
        UIEvent(const std::string& name, KeyAction action)
            : InputEvent(name)
            , m_Action(action) 
        {
        }

        inline const KeyAction& GetAction() const { return m_Action; }

    private:
        KeyAction m_Action;
    };

    class KeyboardEvent : public InputEvent
    {
    public:
        KeyboardEvent(int keyCode, KeyAction action, const std::string& name)
            : InputEvent(name)
            , m_KeyCode(keyCode)
            , m_Action(action) {
        }

        inline int GetKeyCode() const { return m_KeyCode; }
        inline const KeyAction& GetAction() const { return m_Action; }

    private:
        int m_KeyCode;
        KeyAction m_Action;
    };

    class MouseEvent : public InputEvent {  
    public:
        MouseEvent(int mouseButton, MouseAction action, const std::string& name)
            : InputEvent(name)
            , m_MouseButton(mouseButton)
            , m_Action(action) {
        }

        inline int GetMouseButton() const { return m_MouseButton; }
        inline const MouseAction& GetAction() const { return m_Action; }

    private:
        int m_MouseButton{};
        MouseAction m_Action;
    };

    
}