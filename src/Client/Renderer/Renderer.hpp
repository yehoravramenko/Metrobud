#pragma once
#include <tuple>

namespace Metrobud {
class Renderer {
public:
  Renderer(const std::tuple<int, int> size);
  void Update();
  void Draw();
  ~Renderer();
};
} // namespace Metrobud