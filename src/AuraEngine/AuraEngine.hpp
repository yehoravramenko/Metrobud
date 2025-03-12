#pragma once
#include "Input/Input.hpp"
#include "Renderer/Renderer.hpp"
#include "Window/Window.hpp"
#include <memory>

namespace AuraEngine {
class Application;

class Engine {
public:
  Engine();
  void EventLoop();

  bool ShouldExit() const {
    return m_shouldExit;
  }

  friend Application;

private:
  std::tuple<int, int> m_windowSize;
  bool m_shouldExit = false;

  std::unique_ptr<Window> m_window     = nullptr;
  std::unique_ptr<Renderer> m_renderer = nullptr;
  Application *m_application           = nullptr;
};
} // namespace AuraEngine