#pragma once

#include "Event.hpp"

namespace EventSystem
{
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
        UIEvent(KeyAction action)
            : m_Action(action) {
        }

        KeyAction GetAction() const { return m_Action; }
    };

    class KeyboardEvent : public InputEvent
    {
    private:
        int m_KeyCode;
        KeyAction m_Action;

    public:
        KeyboardEvent(int keyCode, KeyAction action)
            : m_KeyCode(keyCode), m_Action(action) {
        }

        int GetKeyCode() const { return m_KeyCode; }
        KeyAction GetAction() const { return m_Action; }
    
    };

    enum class MouseAction
    {
        Pressed,
        Released,
        Repeated,
		Moved,
    };


    class MouseEvent : public InputEvent {
    private:
        int m_MouseButton{ 0 };
		MouseAction m_Action;   
    public:
        MouseEvent(int mouseButton, MouseAction action)
            : m_MouseButton(mouseButton), m_Action(action) {
        }

        int GetMouseButton() const { return m_MouseButton; }
        MouseAction GetAction() const { return m_Action; }
    };

    class InputEvent : public Event {

    };
}