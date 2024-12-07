#include "opengl.hpp"

void GL_Viewport(vec2 coordinates, vec2 size) {
  glViewport(coordinates.x, coordinates.y, size.x, size.y);
}

void GL_SetClearColor(float R, float G, float B, float A) {
  glClearColor(R, G, B, A);
}

void GL_Clear(unsigned int mask) {
  glClear(mask);
}

void GL_VertexAttribPointer(unsigned int index, int count,
                            unsigned int valueType, size_t stride,
                            const void *pointer) {
  glVertexAttribPointer(index, count, valueType, GL_FALSE, stride, pointer);
}

void GL_EnableVertexAttribArray(unsigned int index) {
  glEnableVertexAttribArray(index);
}

void GL_DrawArrays(int mode, int first, int count) {
  glDrawArrays(mode, first, count);
}