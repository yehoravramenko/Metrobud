#pragma once
#include <tuple>

namespace AuraEngine {
class Renderer {
public:
  Renderer(const std::tuple<int, int> size);
  void Update();
  void Draw();
  ~Renderer();
};
} // namespace AuraEngine