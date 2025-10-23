#pragma once 

#include <nlohmann/json.hpp>
#include <string>

namespace Factory {

	using json = nlohmann::json;

	const json TEMPLATE = {
				{"type", ""},
				{"properties", ""}
	};

	class IProduct {
	
	public:
		virtual ~IProduct() = default;
		virtual void LoadFromJson(const json& data) = 0;
		virtual json LoadToJson() = 0;
		
		virtual std::string getClassName() const;

		inline virtual json getJsonTemplate() const { return TEMPLATE; }

	private:
		const int c_classNameOffset = 6;

	};
}