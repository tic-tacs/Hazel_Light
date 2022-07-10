#pragma once

#include <iostream>

#ifdef HZ_PLATFORM_WINDOWS
extern Hazel::Application* Hazel::CreateApplication();
int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized Log");

	Hazel::Application* app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif