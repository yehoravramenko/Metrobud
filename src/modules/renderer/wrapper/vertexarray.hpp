#pragma once

#include "common.hpp"

typedef struct VertexArray {
  unsigned int id;
} VertexArray;

void VertexArray_New(VertexArray *self);
void VertexArray_Bind(VertexArray *self);
void VertexArray_Free(VertexArray *self);