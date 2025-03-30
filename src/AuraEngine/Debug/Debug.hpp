#pragma once
#include "AE_API.hpp"
#include <string_view>

namespace AuraEngine::Debug
{
  AE_API void Log(std::string_view message);
  AE_API void Warning(std::string_view message);
  AE_API void Error(std::string_view message, int exitCode = -1);
} // namespace AuraEngine::Debug