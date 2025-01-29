#pragma once
#include <glad/glad.h>

namespace AuraEngine {
  class VertexAttribPointer
  {
  public:
    VertexAttribPointer(int length, GLenum type, GLboolean normalized, int stride, int startOffset);
    void Enable() const;
    void Disable() const;

  private:
    static int GLOBAL_INDEX;

    unsigned int index;
    int length;
    GLenum type;
    GLboolean normalized;
    GLsizei stride;
    void *startOffset;
  };
}