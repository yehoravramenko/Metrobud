#include "Buffer.hpp"

namespace AuraEngine::OpenGL {
Buffer::Buffer(const GLenum target) {
  m_target = target;
  glCreateBuffers(1, &m_handle);
}

void Buffer::Bind() const {
  glBindBuffer(m_target, m_handle);
}

void Buffer::Data(const size_t size, const void *data,
                  const GLenum usage) const {
  glNamedBufferData(m_handle, size, data, usage);
}

Buffer::~Buffer() {
  glDeleteBuffers(1, &m_handle);
}
} // namespace AuraEngine::OpenGL