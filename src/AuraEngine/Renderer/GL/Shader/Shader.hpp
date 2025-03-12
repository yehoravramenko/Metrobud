#pragma once
#include "glad/glad.h"

namespace AuraEngine::GL {
class Shader {
public:
  Shader(const char *vertexShaderSrc, const char *fragmentShaderSrc);

private:
  unsigned m_program;

  static unsigned compileShader(const char *src, GLenum type);
};
} // namespace AuraEngine::GL