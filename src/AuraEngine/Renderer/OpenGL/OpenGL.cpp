#include "OpenGL.hpp"
#include "glad/glad.h"

namespace AuraEngine::OpenGL {
void VertexAttribPointer(const int index, const int size, const int stride,
                         int offset) {
  glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float),
                        (void *)(offset * sizeof(float)));
}

void EnableVertexAttribArray(const int index) {
  glEnableVertexAttribArray(index);
}

} // namespace AuraEngine::OpenGL