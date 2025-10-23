#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include "Utils/DebugUtils.h"

namespace Serializtion
{
    constexpr std::size_t DEFAULT_JSON_EXT_LENGTH = 5;

    nlohmann::json FileManager::loadJson( const std::string& relativePath, std::string& fileName)
    {
        if (fileName.length() < DEFAULT_JSON_EXT_LENGTH || fileName.substr(fileName.length() - DEFAULT_JSON_EXT_LENGTH) != ".json")
            fileName += ".json";

        auto fromfile = std::ifstream(relativePath + fileName);
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

    void FileManager::saveJson( const std::string& relativePath, std::string& fileName, const nlohmann::json& j)
    {
        if (fileName.length() < DEFAULT_JSON_EXT_LENGTH || fileName.substr(fileName.length() - DEFAULT_JSON_EXT_LENGTH) != ".json")
            fileName += ".json";

        auto fullPath = std::filesystem::path(relativePath + fileName);
        try {
            auto outFile = std::ofstream(fullPath);
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

}
