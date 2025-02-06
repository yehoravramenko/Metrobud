#include "Shader.hpp"
#include "../Log/Log.hpp"
#include <glad/glad.h>

namespace AuraEngine {
  void Shader::_compileShader(unsigned int &shader, const char *shaderSource) const
  {
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);

    int success = 0;
    char infoLog[512]{};
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      glGetShaderInfoLog(shader, 512, nullptr, infoLog);
      Log::EngineLog.Error(std::string("Failed to compile shader.\nDetails: ") + infoLog);
    }
    glAttachShader(this->programId, shader);
  }

  Shader::Shader(const char *vertexShaderSrc, const char *fragmentShaderSrc)
  {
    this->programId = glCreateProgram();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    this->_compileShader(vertexShader, vertexShaderSrc);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    this->_compileShader(fragmentShader, fragmentShaderSrc);

    glLinkProgram(this->programId);

    int success = 0;
    char infoLog[512]{};
    glGetProgramiv(this->programId, GL_LINK_STATUS, &success);
    if (!success)
    {
      glGetProgramInfoLog(this->programId, 512, nullptr, infoLog);
      Log::EngineLog.Error(std::string("Failed to link program.\nDetails: ") + infoLog);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
  }

  void Shader::Use() const
  {
    glUseProgram(this->programId);
  }

  void Shader::SetInt(const std::string &name, int value) const
  {
    glUniform1i(glGetUniformLocation(this->programId, name.c_str()), value);
  }

  void Shader::SetMat4(const std::string &name, const glm::mat4 &matrix) const
  {
    glUniformMatrix4fv(this->GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
  }

  int Shader::GetUniformLocation(const std::string &name) const
  {
    return glGetUniformLocation(this->programId, name.c_str());
  }
}