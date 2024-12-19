#pragma once
#include <common.hpp>

namespace GL {
class Buffer {
public:
  Buffer(unsigned int target);
  void Data(size_t size, const void *data, unsigned int usage);

private:
  unsigned int id = 0;
  unsigned int target = 0;
};
} // namespace GL