#pragma once

#include "raylib.h"

namespace DebugUtils
{

	class FullScreenToggle
	{
	public:
		static void ToggleFullScreen();
		static int GetDisplayWidth();
		static int GetDisplayHeight();

	private:
		static int s_windowedWidth;
		static int s_windowedHeight;
	};

}