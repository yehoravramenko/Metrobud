#include "Buffer.hpp"

namespace AuraEngine::OpenGL
{
  Buffer::Buffer(const GLenum target)
  {
    this->target = target;
    glCreateBuffers(1, &this->handle);
  }

  void Buffer::Bind() const
  {
    glBindBuffer(this->target, this->handle);
  }

  void Buffer::Data(const size_t size, const void *data,
    const GLenum usage) const
  {
    glNamedBufferData(this->handle, size, data, usage);
  }

  Buffer::~Buffer()
  {
    glDeleteBuffers(1, &this->handle);
  }
} // namespace AuraEngine::OpenGL