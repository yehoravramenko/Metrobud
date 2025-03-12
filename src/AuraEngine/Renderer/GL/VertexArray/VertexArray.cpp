#include "VertexArray.hpp"
#include "glad/glad.h"

namespace AuraEngine::GL {
VertexArray::VertexArray() {
  glCreateVertexArrays(1, &m_handle);
}

void VertexArray::Bind() const {
  glBindVertexArray(m_handle);
}

VertexArray::~VertexArray() {
  glDeleteVertexArrays(1, &m_handle);
}
} // namespace AuraEngine::GL