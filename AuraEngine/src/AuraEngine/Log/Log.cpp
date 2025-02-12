#include "Log.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define RST "\x1B[0m"

namespace AuraEngine
{
    LogStream::LogStream(const LogStreamSource src)
    {
        this->src = src;
    }

    void LogStream::Print(const std::string& msg, const LogLevel level) const
    {
        using std::chrono::system_clock;
        const auto now = system_clock::to_time_t(system_clock::now());
        std::string colorCode;
        switch (level)
        {
        case LogLevel::INFO:
            colorCode = KGRN;
            break;
        case LogLevel::WARN:
            colorCode = KYEL;
            break;
        case LogLevel::ERROR:
            colorCode = KRED;
            break;
        }

        std::string source;
        switch (this->src)
        {
        case LogStreamSource::ENGINE:
            source = "ENGINE";
            break;
        case LogStreamSource::CLIENT:
            source = "CLIENT";
            break;
        }

        std::cout << colorCode;
        std::cout << "[" << std::put_time(std::localtime(&now), "%H:%M:%S") << "] " << source << ": " << msg << RST
                  << std::endl;
    }

    void LogStream::Info(const std::string& msg) const
    {
        LogStream::Print(msg, LogLevel::INFO);
    }

    void LogStream::Warn(const std::string& msg) const
    {
        LogStream::Print(msg, LogLevel::WARN);
    }

    void LogStream::Error(const std::string& msg) const
    {
        LogStream::Print(msg, LogLevel::ERROR);
        std::exit(-1);
    }

    LogStream Log::ClientLog(LogStreamSource::CLIENT);
    LogStream Log::EngineLog(LogStreamSource::ENGINE);
} // namespace AuraEngine
