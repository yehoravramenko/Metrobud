#pragma once

#include "common.hpp"

class VertexArray {
public:
  VertexArray();
  void Bind();

private:
  unsigned int id;
};