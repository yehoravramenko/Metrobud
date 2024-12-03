#include "shader.h"

void Shader_New(Shader *self, const char *vertexShaderSrc,
                const char *fragmentShaderSrc) {
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSrc, NULL);
  glCompileShader(vertexShader);
}