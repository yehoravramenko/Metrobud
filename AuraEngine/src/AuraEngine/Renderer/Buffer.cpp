#include "Buffer.hpp"

namespace AuraEngine {
  Buffer::Buffer(GLenum target)
  {
    this->target = target;
    glGenBuffers(1, &this->Id);
  }

  void Buffer::Bind()const
  {
    glBindBuffer(this->target, this->Id);
  }

  void Buffer::SetData(size_t size, const GLvoid *data, GLenum usage) const
  {
    glBufferData(this->target, size, data, usage);
  }
}