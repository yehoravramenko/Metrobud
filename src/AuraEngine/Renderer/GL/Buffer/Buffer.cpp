#include "Buffer.hpp"

namespace AuraEngine::GL {
Buffer::Buffer(const GLenum target) {
  this->target = target;
  glCreateBuffers(1, &this->buffer);
}

void Buffer::Bind() const {
  glBindBuffer(this->target, this->buffer);
}

void Buffer::Data(size_t size, const void *data, GLenum usage) const {
  glNamedBufferData(this->buffer, size, data, usage);
}

Buffer::~Buffer() {
  glDeleteBuffers(1, &this->buffer);
}
} // namespace AuraEngine::GL