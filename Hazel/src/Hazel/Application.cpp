#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Log.h"
namespace Hazel
{
	Application::Application()
	{
	}

	Application::~Application()
	{

	}
	void Application::Run()
	{
		KeyPressedEvent e{ 1280, 720 };
		// Application Loop
		while(true)
		{
			HZ_INFO(e);
		}
	}
}