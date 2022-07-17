#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace rfe
{
	class RF_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define RF_CORE_TRACE(...)   ::rfe::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RF_CORE_INFO(...)    ::rfe::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RF_CORE_WARN(...)    ::rfe::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RF_CORE_ERROR(...)   ::rfe::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RF_CORE_CRITICAL(...)   ::rfe::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define RF_CLIENT_TRACE(...) ::rfe::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RF_CLIENT_INFO(...)  ::rfe::Log::GetClientLogger()->info(__VA_ARGS__)
#define RF_CLIENT_WARN(...)  ::rfe::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RF_CLIENT_ERROR(...) ::rfe::Log::GetClientLogger()->error(__VA_ARGS__)
#define RF_CLIENT_CRITICAL(...) ::rfe::Log::GetClientLogger()->critical(__VA_ARGS__)

