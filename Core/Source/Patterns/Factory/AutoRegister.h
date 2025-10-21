#pragma once

#include "ObjectFactory.h"

namespace Factory
{
    template<typename T>
    struct AutoRegister {
        AutoRegister() {
            ObjectFactory::instance().registerType<T>();
        }
    };

#define REGISTER_TYPE(CLASS) \
    static AutoRegister<CLASS> autoRegister_##CLASS;

}