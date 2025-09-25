#pragma once

#include "raylib.h"

class FullScreenToggle
{
private:
	static int windowedWidth;
	static int windowedHeight;

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
			SetWindowSize(windowedWidth, windowedHeight);
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

};