#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "Utils/DebugUtils.h"

namespace Serializtion
{
	using json = nlohmann::json;

	class FileManager {
	public:
		static nlohmann::json loadJson(const std::string& relativePath, std::string& fileName);
		static void saveJson(const std::string& relativePath, std::string& fileName, const nlohmann::json& j);

	};
}