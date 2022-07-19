#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#pragma once

#include "Hazel/Layer.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/Events/KeyEvent.h"

namespace Hazel {
    class HAZEL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        void OnAttatch() override;
        void OnDetatch() override;
        void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}

#endif