#pragma once
#include <common.hpp>
#include <window/window.hpp>
#include <renderer/renderer.hpp>

namespace Metrobud {
class Client {
public:
  Client(int &, char **);
  void Update();
  void Exit(int &);

  bool shouldClose();

private:
  std::vector<std::string> argv;

  std::unique_ptr<Window> window;
  std::unique_ptr<Renderer> renderer;
};
} // namespace Metrobud