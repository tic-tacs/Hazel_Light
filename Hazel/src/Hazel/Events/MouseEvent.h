#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#pragma once

#include "Event.h"
namespace Hazel
{
    class HAZEL_API MouseMoveEvent : public Event
    {
    public:
        MouseMoveEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y){}
        
        inline float GetX() const {return m_MouseX;}
        inline float GetY() const {return m_MouseY;}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }
        
        EVENT_CLASS_TYPE(MouseMoved);
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
    private:
        float m_MouseX, m_MouseY;
    };

    class HAZEL_API MouseScrollEvent : public Event
    {
    public:
        MouseScrollEvent(float xOffset, float yOffset)
            :m_xOffset(xOffset), m_yOffset(yOffset){}
        
        inline float GetXOffset() const {return m_xOffset;}
        inline float GetYOffset() const {return m_yOffset;}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
            return ss.str();
        }
        
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
        EVENT_CLASS_TYPE(MouseScrolled);
    private:
        float m_xOffset, m_yOffset;
    };

    class HAZEL_API MouseButtonEvent : public Event
    {
    public:
        inline int GetMouseButton() const {return m_Button;}

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
    protected:
        MouseButtonEvent(int button)
            : m_Button(button){}
        int m_Button;
    };

    class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            :MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
            :MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleased: " << m_Button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}
#endif