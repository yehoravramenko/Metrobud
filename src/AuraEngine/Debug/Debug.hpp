#pragma once
#include <string_view>

namespace AuraEngine::Debug {

void Log(std::string_view message);

void Warning(std::string_view message);

void Error(std::string_view message, int exitCode = -1);

} // namespace AuraEngine::Debug