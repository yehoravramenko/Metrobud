#pragma once
#include "../DllCore.hpp"
#include <string>

namespace AuraEngine {

enum class LogLevel { INFO = 0, WARN, ERROR };
enum class LogStreamSource { ENGINE = 0, CLIENT };

class AE_API LogStream {
public:
  LogStream(LogStreamSource src);

  // TODO: add variadic
  void Info(const std::string &msg);
  void Warn(const std::string &msg);
  void Error(const std::string &msg);

private:
  LogStreamSource src;

  void Print(const std::string &msg, LogLevel level);
};

class AE_API Log {
public:
  static LogStream ClientLog;
  static LogStream EngineLog;
};

} // namespace AuraEngine