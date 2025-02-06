#pragma once
#include <string>
#include <glm/ext/matrix_float4x4.hpp>

namespace AuraEngine {
  class Shader
  {
  public:
    Shader(const char *vertexShaderSrc, const char *fragmentShaderSrc);
    void Use() const;
    void SetInt(const std::string &name, int value) const;
    void SetMat4(const std::string &name, const glm::mat4 &matrix) const;
    int GetUniformLocation(const std::string &name) const;

  private:
    unsigned int programId;

    void _compileShader(unsigned int &shader, const char *shaderSource) const;
  };
}