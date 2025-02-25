#include "Debug.hpp"

#include <cstdlib>
#include <print>
#include <string>

enum LogType { Log, Warning, Error };

namespace AuraEngine::Debug {
void _print(LogType logType, std::string_view msg) {
  std::string fmt = "";
  switch (logType) {
  case LogType::Log:
    fmt = "32;1mLOG";
    break;
  case LogType::Warning:
    fmt = "33;1mWARNING";
    break;
  case LogType::Error:
    fmt = "31;1mERROR";
    break;
  }
  std::println("\x1B[{}:\t{}\x1B[0m", fmt, msg);
}

void Log(std::string_view message) { _print(LogType::Log, message); }

void Warning(std::string_view message) { _print(LogType::Warning, message); }

void Error(std::string_view message, int exitCode) {
  _print(LogType::Error, message);
  std::exit(exitCode);
}

} // namespace AuraEngine::Debug