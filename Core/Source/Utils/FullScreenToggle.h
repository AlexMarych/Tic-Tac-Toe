#pragma once

#include "raylib.h"

namespace DebugUtils
{

	class FullScreenToggle
	{

	public:

		static void ToggleFullScreen()
		{
			if (!IsWindowFullscreen())
			{
				int monitor = GetCurrentMonitor();
				SetWindowSize(
					GetMonitorWidth(monitor),
					GetMonitorHeight(monitor)
				);
				ToggleFullScreen();
			}
			else
			{
				ToggleFullScreen();
				SetWindowSize(s_windowedWidth, s_windowedHeight);
			}
		}

		static int GetDisplayWidth()
		{
			if (IsWindowFullscreen())
			{
				int monitor = GetCurrentMonitor();
				return GetMonitorWidth(monitor);
			}
			else return GetScreenWidth();

		}

		static int GetDisplayHeight()
		{
			if (IsWindowFullscreen())
			{
				int monitor = GetCurrentMonitor();
				return GetMonitorHeight(monitor);
			}
			else return GetScreenHeight();
		}
	private:
		static int s_windowedWidth;
		static int s_windowedHeight;
	};

}