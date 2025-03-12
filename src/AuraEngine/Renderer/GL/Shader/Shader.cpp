#include "Shader.hpp"
#include <Debug/Debug.hpp>
#include <format>

namespace AuraEngine::GL {
Shader::Shader(const char *vertexShaderSrc, const char *fragmentShaderSrc) {
  GLuint vert = Shader::compileShader(vertexShaderSrc, GL_VERTEX_SHADER);
  GLuint frag = Shader::compileShader(fragmentShaderSrc, GL_FRAGMENT_SHADER);

  m_program = glCreateProgram();
  glAttachShader(m_program, vert);
  glAttachShader(m_program, frag);
  glLinkProgram(m_program);
  int failure;
  glGetProgramiv(m_program, GL_LINK_STATUS, &failure);
  if (failure) {
    char info[512];
    glGetProgramInfoLog(m_program, 512, nullptr, info);
    Debug::Error(
        std::format("Failed to link program. Details:\n (%s)\n", info));
  }
}

unsigned Shader::compileShader(const char *src, GLenum type) {
  unsigned shader = glCreateShader(type);
  glShaderSource(shader, 1, &src, nullptr);
  glCompileShader(shader);
  int failure;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &failure);
  if (failure) {
    char info[512];
    glGetShaderInfoLog(shader, 512, nullptr, info);
    Debug::Error(
        std::format("Failed to compile shader. Details:\n (%s)\n", info));
  }
  return shader;
}
} // namespace AuraEngine::GL