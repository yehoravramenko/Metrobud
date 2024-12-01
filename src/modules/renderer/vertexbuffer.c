#include "vertexbuffer.h"

void VertexBuffer_Generate(unsigned int *self) {
  glGenBuffers(1, self);
}

void VertexBuffer_Bind(unsigned int self, int target) {
  glBindBuffer(target, self);
}
