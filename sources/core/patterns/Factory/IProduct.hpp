#pragma once 

#include <nlohmann/json.hpp>
#include <string>

namespace Factory {

	class IProduct {
	private:
		const int classNameOffset = 6;
		const nlohmann::json jsonTemplate = {
				{"type", ""},
				{"properties", ""},
				{"objects", ""}
		};

	public:
		virtual ~IProduct() = default;
		virtual void LoadFromJson(const nlohmann::json& data) = 0;
		virtual nlohmann::json LoadToJson() = 0;
		virtual std::string getClassName() const {
			std::string name = typeid(*this).name(); 

			if (name.size() > classNameOffset) {
				name.erase(0, classNameOffset);
			}

			return name;
		}

		virtual nlohmann::json getJsonTemplate() const { return jsonTemplate; }
	};
}