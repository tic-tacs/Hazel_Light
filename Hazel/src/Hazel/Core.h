#ifndef CORE_H
#define CORE_H

#pragma once

#ifdef HZ_PLATFORM_WINDOWS
    #ifdef HZ_BUILD_DLL
        #define HAZEL_API __declspec(dllexport)
    #else
        #define HAZEL_API __declspec(dllimport)
    #endif
#else
    #error Hazel Only Supports Windows
#endif

#define BIT(x) (1 << x)

#endif