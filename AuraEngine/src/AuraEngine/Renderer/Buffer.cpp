#include "Buffer.hpp"

namespace AuraEngine {
  Buffer::Buffer(const GLenum target)
  {
    this->target = target;
    glGenBuffers(1, &this->Id);
  }

  void Buffer::Bind()const
  {
    glBindBuffer(this->target, this->Id);
  }

  void Buffer::SetData(const size_t size, const GLvoid *data, const GLenum usage) const
  {
    glBufferData(this->target, static_cast<GLsizeiptr>(size), data, usage);
  }
}