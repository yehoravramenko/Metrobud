#pragma once
#include "../GLObject.hpp"

namespace AuraEngine::GL {
class VertexArray : private GLObject {
public:
  VertexArray();
  void Bind() const;
  ~VertexArray();
};
} // namespace AuraEngine::GL