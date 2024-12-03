#pragma once

#include <common.h>

typedef struct Buffer {
  unsigned int id;
  unsigned int target;
} Buffer;

void Buffer_Generate(Buffer *self, unsigned int target);
void Buffer_Data(Buffer *self, size_t size, const void *data,
                 unsigned int usage);
void Buffer_Free(Buffer *self);