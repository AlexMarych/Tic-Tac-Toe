#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "Utils/DebugUtils.h"

using json = nlohmann::json;

class FileManager {

public:

	static nlohmann::json loadJson(const std::string& basePath, const std::string& relativePath, std::string& fileName)
	{
		if (fileName.length() < 5 || fileName.substr(fileName.length() - 5) != ".json")
			fileName += ".json";


		std::ifstream fromfile(basePath + relativePath + fileName);

		nlohmann::json j;
		try {
			fromfile >> j;
		}
		catch (const nlohmann::json::parse_error& e) {
			std::cerr << "Parse error: " << e.what() << std::endl;
			return nlohmann::json(); 
		}
		fromfile.close();

		return j;
	}

	static void saveJson(const std::string& basePath, const std::string& relativePath, std::string& fileName, const nlohmann::json& j)
	{

		if (fileName.length() < 5 || fileName.substr(fileName.length() - 5) != ".json")
			fileName += ".json";

		auto fullPath = std::filesystem::path(basePath + relativePath + fileName);
		try 
		{
			std::ofstream outFile(fullPath);
			if (!outFile.is_open()) {
				DebugUtils::println(std::string("FileManager::saveJson: could not open file for write: ") + fullPath.string());
				return;
			}

			outFile << j.dump(4) << std::endl;
			outFile.close();

		}
		catch (const std::exception& e)
		{
			DebugUtils::println(std::string("FileManager::saveJson: exception: ") + e.what());
			return;
		}
	}
};