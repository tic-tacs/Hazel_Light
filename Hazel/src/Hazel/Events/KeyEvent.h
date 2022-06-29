#ifndef KEYEVENT_H
#define KEYEVENT_H

#pragma once

#include "Event.h"

namespace Hazel{
    class HAZEL_API KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const {return m_KeyCode;}

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keyCode)
            :m_KeyCode(keyCode){}

        int m_KeyCode;
    };  

    class HAZEL_API KeyPressedEvent : public KeyEvent
    {
        public:
            KeyPressedEvent(int keycode, int repeatCount)
                :KeyEvent(keycode), m_RepeatCount(repeatCount){}
            
            inline int GetRepeatCount() {return m_RepeatCount;}

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyPressed)
        private:
            int m_RepeatCount;
    };

    class HAZEL_API KeyReleasedEvent : public KeyEvent
    {
        public:
            KeyReleasedEvent(int keycode)
                :KeyEvent(keycode){}
            
            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "KeyReleaseEvent :" << m_KeyCode;
                return ss.str();
            }
        
        EVENT_CLASS_TYPE(KeyReleased)
    };
}

#endif