#pragma once
#include <common.hpp>

namespace Metrobud {
class Window {
public:
  Window();
  void Update();
  void Exit();

  bool shouldClose();
  std::array<int, 4> getRect();

private:
  std::unique_ptr<RGFW_window> pWindow;
};
} // namespace Metrobud