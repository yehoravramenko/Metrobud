#pragma once
#include "../GLObject.hpp"
#include "glad/glad.h"

namespace AuraEngine::GL {
class Buffer : private GLObject {
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
  GLenum m_target;
};
} // namespace AuraEngine::GL