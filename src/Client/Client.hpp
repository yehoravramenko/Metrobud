#pragma once
#include "Renderer/Renderer.hpp"
#include "Window/Window.hpp"

namespace Metrobud {
class Client {
public:
  Client();
  ~Client();
  void EventLoop();

  auto ShouldExit() const -> bool { return this->shouldExit; }

private:
  std::tuple<int, int> size;

  Window *window = nullptr;
  bool shouldExit = false;

  Renderer *renderer = nullptr;

}; // namespace Metrobud
} // namespace Metrobud