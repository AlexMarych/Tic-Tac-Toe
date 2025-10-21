#pragma once

#include "Event.h"

namespace EventSystem
{

    class InputEvent : public Event {
    public:
        InputEvent(const std::string& name) : Event(name) {};
        virtual ~InputEvent() = default;
    };

    enum class KeyAction
    {
        Pressed,
        Released,
        Repeated
    };

    class UIEvent : public InputEvent
    {
	private:
        KeyAction m_Action;
	public:
        UIEvent(const std::string& name, KeyAction action)
            : InputEvent(name), m_Action(action) 
        {
        }

        KeyAction GetAction() const { return m_Action; }
    };

    class KeyboardEvent : public InputEvent
    {
    private:
        int m_KeyCode;
        KeyAction m_Action;

    public:
        KeyboardEvent(int keyCode, KeyAction action, const std::string& name)
            : InputEvent(name), m_KeyCode(keyCode), m_Action(action) {
        }

        int GetKeyCode() const { return m_KeyCode; }
        KeyAction GetAction() const { return m_Action; }
    
    };

    enum class MouseAction
    {
        Pressed,
        Released,
        Repeated,
		Moved
    };


    class MouseEvent : public InputEvent {
    private:
        int m_MouseButton{ 0 };
		MouseAction m_Action;   
    public:
        MouseEvent(int mouseButton, MouseAction action, const std::string& name)
            : InputEvent(name), m_MouseButton(mouseButton), m_Action(action) {
        }

        int GetMouseButton() const { return m_MouseButton; }
        MouseAction GetAction() const { return m_Action; }
    };

    
}