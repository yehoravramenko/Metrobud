#include "buffer.hpp"

Buffer::Buffer(unsigned int target) {
  glGenBuffers(1, &this->id);
  this->target = target;
}

void Buffer::Data(size_t size, const void *data, unsigned int usage) {
  glBindBuffer(this->target, this->id);
  glBufferData(this->target, size, data, usage);
}

// DEBUG_MSG("Free buffer at 0x%p, ID is %d", self, self->id);