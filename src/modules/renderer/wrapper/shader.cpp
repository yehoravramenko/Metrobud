#include "shader.hpp"

int Shader::compileShader(unsigned int shaderType, const char *shaderSource) {
  int shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &shaderSource, NULL);
  glCompileShader(shader);
  int success;
  char infoLog[512];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
    ERR_MSG("SHADER: Failed to compile shader\nDetails:\n\n%s", infoLog);
  }
  return shader;
}

Shader::Shader(const char *vertexShaderSrc, const char *fragmentShaderSrc) {
  int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSrc);
  int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSrc);

  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  int success;
  char infoLog[512];
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
    ERR_MSG("PROGRAM: Failed to compile program\nDetails:\n\n%s", infoLog);
  }
  this->id = shaderProgram;
  this->Use();

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::Use() {
  glUseProgram(this->id);
}

Shader::~Shader() {
  this->id = 0;
}