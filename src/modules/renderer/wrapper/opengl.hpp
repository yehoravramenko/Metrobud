#pragma once

#include "common.hpp"
#include "vertexarray.hpp"
#include "shader.hpp"

// void GL_Viewport(vec2 coordinates, vec2 size);

// void GL_SetClearColor(float R, float G, float B, float A);
// void GL_Clear(unsigned int mask);

// // Normalize is false by default
// void GL_VertexAttribPointer(unsigned int index, int count,
//                             unsigned int valueType, size_t stride,
//                             const void *pointer);

// void GL_EnableVertexAttribArray(unsigned int index);

// void GL_DrawArrays(int mode, int first, int count);

namespace GL {

void Viewport(vec2 coordinates, vec2 size);
void Clear(unsigned int mask);
void VertexAttribPointer(unsigned int index, int count, unsigned int valueType,
                         size_t stride, const void *pointer);
void EnableVertexAttribArray(unsigned int index);
void DrawArrays(int mode, int first, int count);

} // namespace GL