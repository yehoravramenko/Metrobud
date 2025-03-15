#pragma once
#include "../OpenGLObject.hpp"

namespace AuraEngine::OpenGL {
class VertexArray : private OpenGLObject {
public:
  VertexArray();
  void Bind() const;
  ~VertexArray();
};
} // namespace AuraEngine::OpenGL