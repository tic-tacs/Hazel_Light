#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#pragma once
#include "Hazel/Layer.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/Events/KeyEvent.h"

#include <GLFW/glfw3.h>
#include "Platform/OpenGL/ImGuiRenderer.h"

#include "Hazel/Application.h"
namespace Hazel {
    class HAZEL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        void OnAttatch() override;
        void OnDetatch() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;
    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMoveEvent& e);
        bool OnMouseScrollEvent(MouseScrollEvent& e);

        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);

        bool OnWindowResize(WindowResizeEvent& e);

    private:
        float m_Time = 0.0f;

    };
}

#endif