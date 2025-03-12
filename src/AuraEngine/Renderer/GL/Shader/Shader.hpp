#pragma once
#include "glad/glad.h"
#include <string>

namespace AuraEngine::GL {
class Shader {
public:
  Shader(const std::string vertexShaderSrc,
         const std::string fragmentShaderSrc);

  void Use() const;

private:
  unsigned m_program;

  static unsigned compileShader(const std::string &src, const GLenum type);
};
} // namespace AuraEngine::GL