#pragma once
#include "glad/glad.h"

namespace AuraEngine::GL {
class Buffer {
public:
  Buffer(const GLenum target);
  void Bind() const;
  void Data(size_t size, const void *data, GLenum usage = GL_STATIC_DRAW) const;
  ~Buffer();

private:
  unsigned buffer;
  GLenum target;
};
} // namespace AuraEngine::GL