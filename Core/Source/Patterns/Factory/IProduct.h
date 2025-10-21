#pragma once 

#include <nlohmann/json.hpp>
#include <string>

namespace Factory {

	class IProduct {
	
	public:
		virtual ~IProduct() = default;
		virtual void LoadFromJson(const nlohmann::json& data) = 0;
		virtual nlohmann::json LoadToJson() = 0;
		virtual std::string getClassName() const {
			std::string name = typeid(*this).name(); 

			if (name.size() > c_classNameOffset) {
				name.erase(0, c_classNameOffset);
			}

			return name;
		}

		virtual nlohmann::json getJsonTemplate() const { return c_jsonTemplate; }

	private:
		const int c_classNameOffset = 6;
		const nlohmann::json c_jsonTemplate = {
				{"type", ""},
				{"properties", ""}
		};
	};
}