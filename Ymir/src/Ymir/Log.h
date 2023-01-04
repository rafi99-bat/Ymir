#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Ymir {

	class YMIR_API Log
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

// Core log macros
#define YM_CORE_TRACE(...)    ::Ymir::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define YM_CORE_INFO(...)     ::Ymir::Log::GetCoreLogger()->info(__VA_ARGS__)
#define YM_CORE_WARN(...)     ::Ymir::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define YM_CORE_ERROR(...)    ::Ymir::Log::GetCoreLogger()->error(__VA_ARGS__)
#define YM_CORE_FATAL(...)    ::Ymir::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define YM_TRACE(...)	      ::Ymir::Log::GetClientLogger()->trace(__VA_ARGS__)
#define YM_INFO(...)	      ::Ymir::Log::GetClientLogger()->info(__VA_ARGS__)
#define YM_WARN(...)	      ::Ymir::Log::GetClientLogger()->warn(__VA_ARGS__)
#define YM_ERROR(...)	      ::Ymir::Log::GetClientLogger()->error(__VA_ARGS__)
#define YM_FATAL(...)	      ::Ymir::Log::GetClientLogger()->fatal(__VA_ARGS__)