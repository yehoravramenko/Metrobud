#pragma once
#include <common.hpp>
#include <glwrapper/glwrapper.hpp>

namespace Metrobud {
class Renderer {
public:
  Renderer(std::array<int, 4>);
  void Update();
  void Draw();
  void Exit();

private:
  unsigned int clearMask = GL_COLOR_BUFFER_BIT;
  std::unique_ptr<GL::Buffer> VBO;
  std::unique_ptr<GL::Shader> Shader;
};
} // namespace Metrobud