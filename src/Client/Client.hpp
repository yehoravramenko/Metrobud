#pragma once
#include "Renderer/Renderer.hpp"
#include "Window/Window.hpp"
#include <memory>

namespace Metrobud {
class Client {
public:
  Client();
  void EventLoop();

  auto ShouldExit() const -> bool { return this->shouldExit; }

private:
  std::tuple<int, int> size;
  bool shouldExit = false;

  std::unique_ptr<Window> window = nullptr;
  std::unique_ptr<Renderer> renderer = nullptr;
};
} // namespace Metrobud