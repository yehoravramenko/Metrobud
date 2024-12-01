#pragma once

#include <common.h>

typedef struct _VertexBuffer {
  unsigned int id;
} _VertexBuffer;

typedef _VertexBuffer *VertexBuffer;

void VertexBuffer_Generate(unsigned int *self);
void VertexBuffer_Bind(unsigned int self, int target);