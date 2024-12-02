#pragma once

#include <common.h>

typedef struct _Buffer {
  unsigned int id;
  unsigned int target;
} _Buffer;

typedef _Buffer *Buffer;

void Buffer_Generate(Buffer self);
void Buffer_SetTarget(Buffer self, unsigned int target);
void Buffer_Data(Buffer self, size_t size, const void *data,
                 unsigned int usage);
void Buffer_Free(Buffer self);