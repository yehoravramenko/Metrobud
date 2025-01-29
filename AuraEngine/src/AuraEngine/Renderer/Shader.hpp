#pragma once
#include <string>

namespace AuraEngine {
  class Shader
  {
  public:
    Shader(const char *vertexShaderSrc, const char *fragmentShaderSrc);
    void Use() const;

  private:
    unsigned int programId;

    void _compileShader(unsigned int &shader, const char *shaderSource) const;
  };
}