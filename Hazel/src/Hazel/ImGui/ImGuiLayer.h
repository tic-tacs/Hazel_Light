#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#pragma once
#include "Hazel/Layer.h"

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
        float m_Time = 0.0f;

    };
}

#endif