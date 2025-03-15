#pragma once

namespace AuraEngine::OpenGL {
void VertexAttribPointer(const int index, const int size, const int stride,
                         int offset);
void EnableVertexAttribArray(const int index);
} // namespace AuraEngine::OpenGL