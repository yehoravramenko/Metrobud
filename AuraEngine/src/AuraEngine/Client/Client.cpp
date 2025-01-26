#include "Client.hpp"
#include "../Log/Log.hpp"
#include "GLFW/glfw3.h"

namespace AuraEngine {
Client::Client() {
  Log::EngineLog.Info("Testing engine log");
  if (!glfwInit())
    Log::EngineLog.Error("Failed to initialize GLFW");
  // stuff
}
} // namespace AuraEngine