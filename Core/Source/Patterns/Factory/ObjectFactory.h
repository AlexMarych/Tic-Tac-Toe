#pragma once

#include <nlohmann/json.h>
#include "IProduct.h"
#include <unordered_map>
#include <typeindex>
#include <functional>
#include <memory>
using json = nlohmann::json;

namespace Factory
{
    class ObjectFactory {
        using Creator = std::function<std::unique_ptr<IProduct>()>;
        std::unordered_map<std::type_index, Creator> registry;

    public:
        static ObjectFactory& instance() {
            static ObjectFactory f;
            return f;
        }

        template<typename T>
        void registerType() {
            static_assert(std::is_base_of<IProduct, T>::value, "T must derive from IProduct");
            registry[typeid(T)] = []() -> std::unique_ptr<IProduct> 
                {
                    return std::make_unique<T>();
                };
        }

        template<typename T>
        std::unique_ptr<T> create(const json& data) {
            auto it = registry.find(typeid(T));
            if (it == registry.end())
                throw std::runtime_error("Type not registered");

            auto obj = it->second();
            obj->LoadFromJson(data);

            return std::unique_ptr<T>(static_cast<T*>(obj.release()));
        }
    };
}