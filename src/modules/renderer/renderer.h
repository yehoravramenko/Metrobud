#pragma once

#include <common.h>
#include "buffer.h"
#include "shader.h"

typedef struct Renderer {
  unsigned int clearMask;

  Buffer VBO;
  unsigned int VAO;
} Renderer;

Renderer *g_Renderer();

void Renderer_SetClearColor(float R, float G, float B, float A);
void Renderer_SetClearMask(unsigned int mask);

bool Renderer_Init(vec2 viewportSize);
void Renderer_Update();
void Renderer_Exit();