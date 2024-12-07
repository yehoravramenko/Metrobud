#include "vertexarray.hpp"

VertexArray::VertexArray() {
  glGenVertexArrays(1, &this->id);
}

void VertexArray::Bind() {
  glBindVertexArray(this->id);
}