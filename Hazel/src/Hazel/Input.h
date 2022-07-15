#ifndef INPUT_H
#define INPUT_H

#pragma once

#include "Core.h"

namespace Hazel
{
    class HAZEL_API Input
    {
    public:
        // Key Polling
        inline static bool IsKeyPressed(int keycode) {return s_Instance->IsKeyPressedImpl(keycode);}

        // Mouse Polling
        inline static bool IsMouseButtonPressed(int button) {
            return s_Instance->IsMouseButtonPressedImpl(button);}
        inline static float GetMouseX() {
            return s_Instance->GetMouseXImpl();}
        inline static float GetMouseY() {
            return s_Instance->GetMouseYImpl();}
        inline static std::pair<float, float> GetMousePosition() {
            return s_Instance->GetMousePositionImpl();}
             
    protected:
        virtual bool IsKeyPressedImpl(int keycode) = 0;

        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;
    private:
        static Input* s_Instance;
    };

}

#endif