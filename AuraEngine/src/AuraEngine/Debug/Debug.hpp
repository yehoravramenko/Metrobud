#pragma once
#include "../ExportAPI.hpp"
#include <string>

namespace AuraEngine
{
  class Debug
  {
  public:
    AE_API void Log(const std::string &message) const;
  };
}