#include "buffer.hpp"

using namespace GL;

Buffer::Buffer(unsigned int target) {
  this->target = target;
  glGenBuffers(1, &this->id);
}

void Buffer::Data(size_t size, const void *data, unsigned int usage) {
  int last_id = 0;
  glGetIntegerv(this->target + 0x0002, &last_id);

  glBindBuffer(this->target, this->id);
  glBufferData(this->target, size, data, usage);

  glBindBuffer(this->target, last_id);
}