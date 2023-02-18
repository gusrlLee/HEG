#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace HEG {   
    class Log
    {
        public: 
            static void Init();

            inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; } 
            inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; } 

        private:
            static std::shared_ptr<spdlog::logger> s_CoreLogger;
            static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define HEG_CORE_TRACE( ... )   ::HEG::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HEG_CORE_INFO( ... )    ::HEG::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HEG_CORE_WARN( ... )    ::HEG::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HEG_CORE_ERROR( ... )   ::HEG::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HEG_CORE_FATAL( ... )   ::HEG::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HEG_TRACE( ... )   ::HEG::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HEG_INFO( ... )    ::HEG::Log::GetClientLogger()->info(__VA_ARGS__)
#define HEG_WARN( ... )    ::HEG::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HEG_ERROR( ... )   ::HEG::Log::GetClientLogger()->error(__VA_ARGS__)
#define HEG_FATAL( ... )   ::HEG::Log::GetClientLogger()->fatal(__VA_ARGS__)