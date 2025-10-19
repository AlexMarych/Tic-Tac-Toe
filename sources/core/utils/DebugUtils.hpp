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
#ifdef DEBUG
        fmt::print(fmt::runtime(fmt), args...);
#endif
    }

    template <typename... T>
    inline void println(fmt::format_string<T...> fmt, T &&...args)
    {
#ifdef DEBUG
        auto formatted = fmt::format(fmt::runtime(fmt), args...);
        cout << formatted << endl;
#endif
    }
}