#include "opengl.h"

void GL_VertexAttribPointer(unsigned int index, int count,
                            unsigned int valueType, size_t stride,
                            const void *pointer) {
  glVertexAttribPointer(index, count, valueType, GL_FALSE, stride, pointer);
}

void GL_EnableVertexAttribArray(unsigned int index) {
  glEnableVertexAttribArray(index);
}