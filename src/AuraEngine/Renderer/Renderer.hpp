#pragma once
#include "GL/Buffer/Buffer.hpp"
#include <tuple>

namespace AuraEngine {
class Renderer {
public:
  Renderer(const std::tuple<int, int> size);
  Renderer();
  void Update();
  void Draw();
  ~Renderer();

private:
  GL::Buffer VBO{GL_ARRAY_BUFFER};
};
} // namespace AuraEngine