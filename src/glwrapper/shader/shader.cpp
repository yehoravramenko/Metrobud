#include "shader.hpp"

using namespace GL;

void Shader::compileShader(unsigned int &shader_id, const char *src) {
  glShaderSource(shader_id, 1, &src, NULL);
  glCompileShader(shader_id);

  int success = 0;
  char infoLog[512];
  glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader_id, 512, NULL, infoLog);
    std::println("Failed to compile a shader\n {}", infoLog);
    assert(success);
  }
}

Shader::Shader(const std::string &vert_shader_src,
               const std::string &frag_shader_src) {
  auto vertShader = glCreateShader(GL_VERTEX_SHADER);
  auto fragShader = glCreateShader(GL_FRAGMENT_SHADER);

  this->compileShader(vertShader, vert_shader_src.c_str());
  this->compileShader(fragShader, frag_shader_src.c_str());

  this->id = glCreateProgram();
  glAttachShader(this->id, vertShader);
  glAttachShader(this->id, fragShader);

  glLinkProgram(this->id);

  int result = 0;
  char infoLog[512];
  glGetProgramiv(this->id, GL_LINK_STATUS, &result);
  if (!result) {
    glGetShaderInfoLog(this->id, 512, NULL, infoLog);
    std::println("Failed to link a program\n {}", infoLog);
    assert(result);
  }

  glDeleteShader(vertShader);
  glDeleteShader(fragShader);
}