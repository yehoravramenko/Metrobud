#include "vertexarray.h"

void VertexArray_New(VertexArray *self) {
  glGenVertexArrays(1, &self->id);
}

void VertexArray_Bind(VertexArray *self) {
  if (!self) {
    glBindVertexArray(0);
    return;
  }
  glBindVertexArray(self->id);
}

void VertexArray_Free(VertexArray *self) {
  self->id = 0;
  free(self);
}
