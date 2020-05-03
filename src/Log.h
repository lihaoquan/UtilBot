#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace UtilBot {

	class Log
	{
	public:
		static void Init();

		// Inline is used for small functions that are called very often, helps to speed up function call
		// Static functions are allocated to storage only once in a program lifetime, and they have a scope till the end of the program
		// Used in this case because the app will need to gain access to the logger often to log information to the console
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

	private:
		// Smart pointers: https://youtu.be/iChalAKXffs?t=2160
		// It will delete itself when it is no longer used
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}

// Reason for making these as macros is so that when in distribution, we can just define these macros as nothing so it does not get
// included in the built .dll library to reduce size
// Core log macros
// ... means there can be a variable number of arguments. __VA_ARGS__ maps those arguments into itself and passes it to the function
#define CORE_TRACE(...)   ::UtilBot::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)    ::UtilBot::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)    ::UtilBot::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)   ::UtilBot::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...)   ::UtilBot::Log::GetCoreLogger()->fatal(__VA_ARGS__)