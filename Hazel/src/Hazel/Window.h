#ifndef WINDOW_H
#define WINDOW_H

#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Hazel{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Hazel Engine", 
					unsigned int width = 1280, 
					unsigned int height = 720)
				: Title(title), Width(width), Height(height){}
	};

	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		virtual void OnUpdate() = 0;

		inline virtual unsigned int GetWidth() const = 0;
		inline virtual unsigned int GetHeight() const = 0;

		// Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback ) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool isVsync() const = 0;

		// implemented per platform
		static Window* Create(const WindowProps& props = WindowProps());
		virtual void* GetNativeWindow() const = 0;
	};
}

#endif