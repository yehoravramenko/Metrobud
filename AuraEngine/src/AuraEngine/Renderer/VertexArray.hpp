#pragma once
#include <string>
#include <map>
#include <glad/glad.h>
#include "VertexAttribPointer.hpp"

namespace AuraEngine {
  class VertexArray
  {
  public:
    VertexArray();
    void Bind() const;
    static void Unbind();

    void AddVertexAttribPointer(const std::string &name, int length, GLenum type, GLboolean normalized, int stride, int startOffset);

  private:
    unsigned int Id;
    std::map<const std::string, VertexAttribPointer> vertexAttribPointers;
  };
}