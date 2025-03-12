#include "Buffer.hpp"

namespace AuraEngine::GL {
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

void Buffer::VertexAttribPointer(const int index, const int size,
                                 const int stride, int offset) const {
  glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float),
                        (void *)(offset * sizeof(float)));
}

void Buffer::EnableVertexAttribArray(const int index) const {
  glEnableVertexAttribArray(index);
}

Buffer::~Buffer() {
  glDeleteBuffers(1, &m_handle);
}
} // namespace AuraEngine::GL