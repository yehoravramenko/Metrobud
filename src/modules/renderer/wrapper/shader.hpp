#pragma once
#include <common.hpp>

class Shader {
public:
  Shader(const char *vertexShaderSrc, const char *fragmentShaderSrc);
  void Use();
  ~Shader();

private:
  unsigned int id;

  int compileShader(unsigned int shaderType, const char *shaderSource);
};