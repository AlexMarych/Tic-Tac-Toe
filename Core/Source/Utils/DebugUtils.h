#pragma once

#include <string>
#include <iostream>
#include <fmt/core.h>


using namespace std;

namespace DebugUtils
{
   
    template <typename... T>
    inline void print(fmt::format_string<T...> fmt, T &&...args)
    {
        fmt::print(fmt::runtime(fmt), args...);
    }

    template <typename... T>
    inline void println(fmt::format_string<T...> fmt, T &&...args)
    {
        auto formatted = fmt::format(fmt::runtime(fmt), args...);
        cout << formatted << endl;
    }
}