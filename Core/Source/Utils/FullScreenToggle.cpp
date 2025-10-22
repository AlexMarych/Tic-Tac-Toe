#include "FullScreenToggle.h"

namespace DebugUtils
{
    int FullScreenToggle::s_windowedWidth = 800;  
    int FullScreenToggle::s_windowedHeight = 600; 

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
