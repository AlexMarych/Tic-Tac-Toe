

#include "IProduct.h"

namespace Factory {

    std::string IProduct::getClassName() const {

        std::string name = typeid(*this).name();

        if (name.size() > c_classNameOffset) {
            name.erase(0, c_classNameOffset);
        }

        return name;
    }
}