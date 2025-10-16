#pragma once

#include <nlohmann/json.hpp>
#include "raylib.h"
#include <string>
#include "core/patterns/Factory/ObjectFactory.hpp"
#include "core/patterns/Factory/AutoRegister.hpp"
#include "core/patterns/Factory/IProduct.hpp"
#include <map>
#include <iostream>

using namespace Factory;

class Test : public IProduct
{
private:
		std::string text;

public:
	Test() {}

	std::string getText() const { return text; }

	virtual void LoadFromJson(const nlohmann::json& data) override
	{
		if (data.contains("properties")) {
			
			if (data["properties"].contains("text")) {
				text = data["properties"]["text"].get<std::string>();
			}
		}
	}

	virtual nlohmann::json LoadToJson() override
	{
		std::map<std::string, nlohmann::json> properties;
		
		properties["text"] = text;

		nlohmann::json j = getJsonTemplate();
		j["type"] = getClassName();
		j["properties"] = properties;
		return j;
	}
};

REGISTER_TYPE(Test)