#pragma once
#include "../OpenGLObject.hpp"
#include <string>

namespace AuraEngine::OpenGL {
typedef unsigned int GLenum;
class Shader : private OpenGLObject {
public:
  Shader(const std::string vertexShaderSrc,
         const std::string fragmentShaderSrc);

  void Use() const;
  void SetInt(const std::string &name, const int value) const;

private:
  static unsigned compileShader(const std::string &src, const GLenum type);
};
} // namespace AuraEngine::OpenGL