#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include "Utils/DebugUtils.h"

nlohmann::json FileManager::loadJson(const std::string& basePath, const std::string& relativePath, std::string& fileName)
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

void FileManager::saveJson(const std::string& basePath, const std::string& relativePath, std::string& fileName, const nlohmann::json& j)
{
    if (fileName.length() < 5 || fileName.substr(fileName.length() - 5) != ".json")
        fileName += ".json";

    auto fullPath = std::filesystem::path(basePath + relativePath + fileName);
    try {
        std::ofstream outFile(fullPath);
        if (!outFile.is_open()) {
            DebugUtils::println("FileManager::saveJson: could not open file for write: " + fullPath.string());
            return;
        }

        outFile << j.dump(4) << std::endl;
        outFile.close();
    }
    catch (const std::exception& e) {
        DebugUtils::println("FileManager::saveJson: exception: " + std::string(e.what()));
        return;
    }
}
