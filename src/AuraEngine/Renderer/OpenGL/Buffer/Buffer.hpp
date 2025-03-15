#pragma once
#include "../OpenGLObject.hpp"
#include "glad/glad.h"

namespace AuraEngine::OpenGL {
class Buffer : private OpenGLObject {
public:
  Buffer(const GLenum target);
  void Bind() const;
  void Data(const size_t size, const void *data,
            const GLenum usage = GL_STATIC_DRAW) const;

  ~Buffer();

private:
  GLenum m_target;
};
} // namespace AuraEngine::OpenGL