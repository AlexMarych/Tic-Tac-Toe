#pragma once

#include <nlohmann/json.hpp>
#include "IProduct.h"
#include <unordered_map>
#include <typeindex>
#include <functional>
#include <memory>


namespace Factory
{
    using json = nlohmann::json;

    class ObjectFactory {
      
    public:
        static ObjectFactory& instance() {
            static ObjectFactory f;
            return f;
        }

        template<typename T>
        void registerType() {
            static_assert(std::is_base_of<IProduct, T>::value, "T must derive from IProduct");
            m_registry[typeid(T)] = []() -> std::unique_ptr<IProduct> 
                {
                    return std::make_unique<T>();
                };
        }

        template<typename T>
        std::unique_ptr<T> create(const json& data) {
            const auto& it = m_registry.find(typeid(T));
            if (it == m_registry.end())
                throw std::runtime_error("Type not registered");

            auto obj = it->second();
            obj->LoadFromJson(data);

            auto ptr = dynamic_cast<T*>(obj.get());

            if (!ptr) throw std::runtime_error("Failed to cast IProduct to requested type");

            return std::unique_ptr<T>(obj.release());
        }
	private:
        using Creator = std::function<std::unique_ptr<IProduct>()>;
        std::unordered_map<std::type_index, Creator> m_registry{};
    };
}