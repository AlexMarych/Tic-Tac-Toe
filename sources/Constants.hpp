#pragma once

#include <string>

const int ScreenScale = 2;
namespace GameConstants
{
    const int WorldWidth = 400;
    const int WorldHeight = 400;

    const int CellSize = 16;
    const float PhysicsWorldScale = 16.0f / ScreenScale;
}

namespace AppConstants
{
    const std::string WindowTitle = "Angry Pirates";

    const int ScreenWidth = GameConstants::WorldWidth * ScreenScale;
    const int ScreenHeight = GameConstants::WorldHeight * ScreenScale;

	const int TargetFPS = 60;

    inline std::string GetAssetPath(std::string assetName)
    {
        return ASSETS_PATH "" + assetName;
    }
}
