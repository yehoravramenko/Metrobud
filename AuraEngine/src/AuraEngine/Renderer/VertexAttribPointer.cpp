#include "VertexAttribPointer.hpp"

namespace AuraEngine {
  int VertexAttribPointer::GLOBAL_INDEX = -1;

  VertexAttribPointer::VertexAttribPointer(int length, GLenum type, GLboolean normalized, int stride, int startOffset)
  {
    this->index = ++GLOBAL_INDEX;
    this->length = length;
    this->type = type;
    this->normalized = normalized;

    switch (this->type)
    {
    case GL_FLOAT:
    default:
      this->stride = stride * sizeof(float);
      this->startOffset = (void *)(startOffset * sizeof(float));
      break;
    }

    glVertexAttribPointer(this->index, this->length, this->type, this->normalized, this->stride, this->startOffset);
  }

  void VertexAttribPointer::Enable() const
  {
    glEnableVertexAttribArray(this->index);
  }

  void VertexAttribPointer::Disable() const
  {
    glDisableVertexAttribArray(this->index);
  }
}