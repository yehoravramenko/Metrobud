#include "opengl.hpp"

void GL::Viewport(vec2 coordinates, vec2 size) {
  glViewport(coordinates.x, coordinates.y, size.x, size.y);
}

void GL::Clear(unsigned int mask) {
  glClear(mask);
}

void GL::VertexAttribPointer(unsigned int index, int count,
                             unsigned int valueType, size_t stride,
                             const void *pointer) {
  glVertexAttribPointer(index, count, valueType, GL_FALSE, stride, pointer);
}

void GL::EnableVertexAttribArray(unsigned int index) {
  glEnableVertexAttribArray(index);
}

void GL::DrawArrays(int mode, int first, int count) {
  glDrawArrays(mode, first, count);
}