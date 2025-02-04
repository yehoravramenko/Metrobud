#include "Debug.hpp"
#include "../Log/Log.hpp"

namespace AuraEngine {
  void Debug::Log(const std::string &message) const
  {
    Log::ClientLog.Info(message);
  }
}