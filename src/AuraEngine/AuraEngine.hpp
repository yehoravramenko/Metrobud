#pragma once
#include "Input/Input.hpp"
#include "Renderer/Renderer.hpp"
#include "Window/Window.hpp"
#include <memory>

namespace AuraEngine {
class Engine {
public:
  Engine();
  void EventLoop();

  bool ShouldExit() const {
    return this->shouldExit;
  }

  friend class Application;

private:
  std::tuple<int, int> size;
  bool shouldExit = false;

  std::unique_ptr<Window> window     = nullptr;
  std::unique_ptr<Renderer> renderer = nullptr;
  class Application *application     = nullptr;
};
} // namespace AuraEngine