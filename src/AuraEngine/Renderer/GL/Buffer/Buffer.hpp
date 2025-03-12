#pragma once
#include "glad/glad.h"

namespace AuraEngine::GL {
class Buffer {
public:
  Buffer(const GLenum target);
  void Bind() const;
  void Data(const size_t size, const void *data,
            const GLenum usage = GL_STATIC_DRAW) const;
  void VertexAttribPointer(const int index, const int size, const int stride,
                           int offset) const;
  void EnableVertexAttribArray(const int index) const;
  ~Buffer();

private:
  unsigned m_handle;
  GLenum m_target;
};
} // namespace AuraEngine::GL