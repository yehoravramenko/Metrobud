#pragma once
#include "../OpenGLObject.hpp"
#include "glm/mat4x4.hpp"
#include <string>

namespace AuraEngine::OpenGL
{
  using GLenum = unsigned int;
  class Shader : private OpenGLObject
  {
  public:
    Shader(const std::string &vertexShaderSrc,
      const std::string &fragmentShaderSrc);

    void Use() const;

    void SetInt(const std::string &name, const int value) const;
    void SetMat4(const std::string &name, const glm::mat4 &mat) const;

  private:
    static unsigned compileShader(const std::string &src, const GLenum type);
  };
} // namespace AuraEngine::OpenGL