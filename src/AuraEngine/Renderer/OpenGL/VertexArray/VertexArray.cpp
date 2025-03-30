#include "VertexArray.hpp"
#include "glad/glad.h"

namespace AuraEngine::OpenGL
{
  VertexArray::VertexArray()
  {
    glCreateVertexArrays(1, &this->handle);
  }

  void VertexArray::Bind() const
  {
    glBindVertexArray(this->handle);
  }

  VertexArray::~VertexArray()
  {
    glDeleteVertexArrays(1, &this->handle);
  }
} // namespace AuraEngine::OpenGL