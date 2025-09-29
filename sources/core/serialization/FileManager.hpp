#pragma once

#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileManager {
private:
	inline static const std::string basePath = ASSETS_PATH;

public:

	static nlohmann::json loadJson(std::string& relativePath, std::string& fileName)
	{
		if (fileName.length() < 5 || fileName.substr(fileName.length() - 5) != ".json")
			fileName += ".json";

		std::ifstream fromfile(basePath + fileName);

		if (!fromfile.is_open()) {
			std::cerr << "Error: Could not open file!" << std::endl;
			return nlohmann::json(); // Возвращаем пустой json
		}

		nlohmann::json j;
		try {
			fromfile >> j;
		}
		catch (const nlohmann::json::parse_error& e) {
			std::cerr << "Parse error: " << e.what() << std::endl;
			return nlohmann::json(); // Возвращаем пустой json
		}
		fromfile.close();

		return j;
	}

	static void saveJson(std::string& relativePath, std::string& fileName, const nlohmann::json& j)
	{
		if (fileName.length() < 5 || fileName.substr(fileName.length() - 5) != ".json")
			fileName += ".json";

		std::ofstream outFile(basePath + fileName);
		if (!outFile.is_open()) {
			std::cerr << "Error: Could not open output file!" << std::endl;
			return;
		}
		
		outFile << j.dump(4) << std::endl;
		outFile.close();
	}
};