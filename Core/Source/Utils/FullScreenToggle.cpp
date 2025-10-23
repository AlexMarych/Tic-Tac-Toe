#include "FullScreenToggle.h"
#include "Game/Game.h"

namespace DebugUtils
{
    int FullScreenToggle::s_windowedWidth = Core::Game::GetConfig().screenWidth;
    int FullScreenToggle::s_windowedHeight = Core::Game::GetConfig().screenHeight;

    void FullScreenToggle::ToggleFullScreen()
    {
        if (!IsWindowFullscreen())
        {
            s_windowedWidth = GetScreenWidth();
            s_windowedHeight = GetScreenHeight();

            int monitor = GetCurrentMonitor();
            SetWindowSize(
                GetMonitorWidth(monitor),
                GetMonitorHeight(monitor)
            );
            ToggleFullscreen();
        }
        else
        {
            ToggleFullscreen();
            SetWindowSize(s_windowedWidth, s_windowedHeight);
        }
    }

    int FullScreenToggle::GetDisplayWidth()
    {
        if (IsWindowFullscreen())
        {
            int monitor = GetCurrentMonitor();
            return GetMonitorWidth(monitor);
        }
        else
            return GetScreenWidth();
    }

    int FullScreenToggle::GetDisplayHeight()
    {
        if (IsWindowFullscreen())
        {
            int monitor = GetCurrentMonitor();
            return GetMonitorHeight(monitor);
        }
        else
            return GetScreenHeight();
    }
} 
