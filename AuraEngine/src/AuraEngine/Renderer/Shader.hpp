#pragma once
#include <string>

namespace AuraEngine {
  class Shader
  {
  public:
    Shader(const char *vertexShaderSrc, const char *fragmentShaderSrc);
    void Use() const;
    void SetInt(const std::string &name, int value) const;
    void SetMat4(int location, float *value);
    int GetUniformLocation(const std::string &name) const;

  private:
    unsigned int programId;

    void _compileShader(unsigned int &shader, const char *shaderSource) const;
  };
}