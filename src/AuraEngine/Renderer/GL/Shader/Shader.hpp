#pragma once
#include "../GLObject.hpp"
#include "glad/glad.h"
#include <string>

namespace AuraEngine::GL {
class Shader : private GLObject {
public:
  Shader(const std::string vertexShaderSrc,
         const std::string fragmentShaderSrc);

  void Use() const;

private:
  static unsigned compileShader(const std::string &src, const GLenum type);
};
} // namespace AuraEngine::GL