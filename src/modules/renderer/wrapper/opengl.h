#pragma once

#include "common.h"

// Normalize is false by default
void GL_VertexAttribPointer(unsigned int index, int count,
                            unsigned int valueType, size_t stride,
                            const void *pointer);

void GL_EnableVertexAttribArray(unsigned int index);