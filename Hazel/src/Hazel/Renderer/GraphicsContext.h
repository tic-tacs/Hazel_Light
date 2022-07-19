#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

#pragma once


namespace Hazel{
    class GraphicsContext
    {
    public:

        virtual void Init() = 0;
        virtual void SwapBuffers()= 0;
    private:

    };
}

#endif