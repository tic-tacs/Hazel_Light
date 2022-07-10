#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace Hazel{
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        static inline Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        LayerStack m_layerStack;
    private:
        bool OnWindowClosed(WindowCloseEvent& e);

        static Application* s_Instance;
    };

    // To be defined by client
    Application* CreateApplication();
}

#endif