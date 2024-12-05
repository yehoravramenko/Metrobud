#pragma once
#include <common.h>

typedef struct Shader {
  unsigned int id;
} Shader;

void Shader_New(Shader *self, const char *vertexShaderSrc,
                const char *fragmentShaderSrc);
void Shader_Use(Shader *self);
void Shader_Delete(Shader *self);