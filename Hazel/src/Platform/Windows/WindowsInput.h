#ifndef WINDOWSINPUT_H
#define WINDOWSINPUT_H

#pragma once

#include "Hazel/Input.h"

namespace Hazel{
    class WindowsInput : public Input
    {
    protected:
        // Key Input Polling
        virtual bool IsKeyPressedImpl(int keycode) override;

        // Mouse Input Polling
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
    };
}

#endif