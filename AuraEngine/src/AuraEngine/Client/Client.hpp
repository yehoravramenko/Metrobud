#pragma once
#include "../DllCore.hpp"
#include "../Window/Window.hpp"
#include "../Renderer/Renderer.hpp"

namespace AuraEngine {
class AE_API Client {
public:
  Client();

private:
  Window window;
  Renderer renderer;
};
} // namespace AuraEngine