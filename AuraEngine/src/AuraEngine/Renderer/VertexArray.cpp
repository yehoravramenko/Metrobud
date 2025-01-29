#include "VertexArray.hpp"
#include <glad/glad.h>

namespace AuraEngine {
  VertexArray::VertexArray()
  {
    glGenVertexArrays(1, &this->Id);
  }

  void VertexArray::Bind() const
  {
    glBindVertexArray(this->Id);
  }

  void VertexArray::Unbind()
  {
    glBindVertexArray(0);
  }
  void VertexArray::AddVertexAttribPointer(const std::string &name, int length, GLenum type, GLboolean normalized, int stride, int startOffset)
  {
    this->vertexAttribPointers.insert({ name, VertexAttribPointer{length, type, normalized, stride, startOffset} });
    this->vertexAttribPointers.at(name).Enable();
  }
}