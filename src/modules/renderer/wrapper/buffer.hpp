#pragma once

#include <common.hpp>

class Buffer {
public:
  Buffer(unsigned int target);
  void Data(size_t size, const void *data, unsigned int usage);

private:
  unsigned int id;
  unsigned int target;
};