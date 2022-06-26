#include "Log.h"


namespace Hazel{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// timestamp , logger name, message
		spdlog::set_pattern("%^ [%T] %n: %v%$");
		
		s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
		s_ClientLogger = spdlog::stdout_color_mt("APP");
	}

}
