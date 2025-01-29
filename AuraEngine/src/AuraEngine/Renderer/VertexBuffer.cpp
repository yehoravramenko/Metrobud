#include "VertexBuffer.hpp"

namespace AuraEngine {
  VertexBuffer::VertexBuffer(GLenum target)
  {
    this->target = target;
    glGenBuffers(1, &this->Id);
  }

  void VertexBuffer::Bind()const
  {
    glBindBuffer(this->target, this->Id);
  }

  void VertexBuffer::SetData(size_t size, const GLvoid *data, GLenum usage) const
  {
    glBufferData(this->target, size, data, usage);
  }
}