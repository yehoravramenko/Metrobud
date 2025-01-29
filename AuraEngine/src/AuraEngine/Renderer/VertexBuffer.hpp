#pragma once
#include <glad/glad.h>

namespace AuraEngine {
  class VertexBuffer
  {
  public:
    VertexBuffer(GLenum target);
    void Bind() const;
    void SetData(size_t size, const GLvoid *data, GLenum usage = GL_STATIC_DRAW) const;

  private:
    unsigned int Id = 0;
    GLenum target;
  };
}