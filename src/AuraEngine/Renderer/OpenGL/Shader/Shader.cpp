#include "Shader.hpp"
#include "Debug/Debug.hpp"
#include "glad/glad.h"
#include <format>

namespace AuraEngine::OpenGL
{
  Shader::Shader(const std::string &vertexShaderSrc,
    const std::string &fragmentShaderSrc)
  {
    GLuint vert = Shader::compileShader(vertexShaderSrc, GL_VERTEX_SHADER);
    GLuint frag = Shader::compileShader(fragmentShaderSrc, GL_FRAGMENT_SHADER);

    this->handle = glCreateProgram();
    glAttachShader(this->handle, vert);
    glAttachShader(this->handle, frag);
    glLinkProgram(this->handle);
    int success;
    glGetProgramiv(this->handle, GL_LINK_STATUS, &success);
    if(!success)
    {
      char info[512];
      glGetProgramInfoLog(this->handle, 512, nullptr, info);
      Debug::Error(
        std::format("Failed to link program. Details:\n ({})\n", info));
    }
    glDeleteShader(vert);
    glDeleteShader(frag);
  }

  void Shader::Use() const
  {
    glUseProgram(this->handle);
  }

  void Shader::SetInt(const std::string &name, const int value) const
  {
    glUniform1i(glGetUniformLocation(this->handle, name.c_str()), value);
  }

  void Shader::SetMat4(const std::string &name, const glm::mat4 &mat) const
  {
    glUniformMatrix4fv(glGetUniformLocation(this->handle, name.c_str()), 1, GL_FALSE,
      &mat[0][0]);
  }

  unsigned Shader::compileShader(const std::string &src, const GLenum type)
  {
    unsigned shader = glCreateShader(type);
    const char *src_ptr = src.c_str();
    glShaderSource(shader, 1, &src_ptr, nullptr);
    glCompileShader(shader);
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
      char info[512];
      glGetShaderInfoLog(shader, 512, nullptr, info);
      Debug::Error(
        std::format("Failed to compile shader. Details:\n ({})\n", info));
    }
    return shader;
  }
} // namespace AuraEngine::OpenGL