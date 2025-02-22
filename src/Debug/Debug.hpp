#pragma once
#include <string_view>

namespace Metrobud::Debug {

void
Log(std::string_view message);

void
Warning(std::string_view message);

void
Error(std::string_view message, int exitCode = -1);

} // namespace Metrobud::Debug