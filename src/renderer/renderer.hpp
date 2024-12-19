#pragma once
#include <common.hpp>

namespace Metrobud {
class Renderer {
public:
  Renderer(std::array<int, 4>);
  void Update();
  void Draw();
  void Exit();

private:
  unsigned int clearMask = GL_COLOR_BUFFER_BIT;
};
} // namespace Metrobud