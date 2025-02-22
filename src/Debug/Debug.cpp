#include "Debug.hpp"

#include <cstdlib>
#include <print>
#include <string>
#include <string_view>

enum LogType { Log, Warning, Error };

void _print(LogType logType, std::string_view msg) {
  std::string fmt = "\x1B[";
  switch (logType) {
  case LogType::Log:
    fmt = "32;1mLOG";
    break;
  case LogType::Warning:
    fmt = "33;1mWARNING";
    break;
  case LogType::Error:
    fmt = "31;1mERROR:";
    break;
  }
  std::println("{}:\t{}\x1B[0m", fmt, msg);
}

namespace Metrobud::Debug {

void Log(std::string_view message) { _print(LogType::Log, message); }

void Warning(std::string_view message) { _print(LogType::Warning, message); }

void Error(std::string_view message, int exitCode) {
  _print(LogType::Error, message);
  std::exit(exitCode);
}

} // namespace Metrobud::Debug