#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include "Core.h"

namespace Hazel{
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined by client
    Application* CreateApplication();
}

#endif