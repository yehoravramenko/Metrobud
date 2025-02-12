#pragma once
#include <string>
#include "../ExportAPI.hpp"

namespace AuraEngine
{

    enum class LogLevel
    {
        INFO = 0,
        WARN,
        ERROR
    };
    enum class LogStreamSource
    {
        ENGINE = 0,
        CLIENT
    };

    class LogStream
    {
    public:
        explicit LogStream(LogStreamSource src);

        // TODO: add variadic
        void Info(const std::string& msg) const;
        void Warn(const std::string& msg) const;
        void Error(const std::string& msg) const;

    private:
        LogStreamSource src;

        void Print(const std::string& msg, LogLevel level) const;
    };

    class Log
    {
    public:
        static LogStream ClientLog;
        static LogStream EngineLog;
    };

} // namespace AuraEngine
