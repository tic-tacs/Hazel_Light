#ifndef LAYER_H
#define LAYER_H

#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {
    class HAZEL_API Layer
    {
    public:
        Layer(const std::string& name = "Layer");

        virtual ~Layer();
        virtual void OnAttatch()    {}
        virtual void OnDetatch()    {}
        virtual void OnUpdate()     {}
        virtual void OnEvent(Event& event) {}
        
        inline const std::string& GetName() const {return m_DebugName;}

    private:
        std::string m_DebugName;


    };
}

#endif