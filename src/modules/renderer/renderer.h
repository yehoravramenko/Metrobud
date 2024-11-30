#pragma once

#include <common.h>

typedef struct _Renderer {
  unsigned int clearMask;

  unsigned int VAO;
  unsigned int VBO;
} _Renderer;

typedef _Renderer *Renderer;

Renderer g_Renderer();

void Renderer_SetClearColor(float R, float G, float B, float A);
void Renderer_SetClearMask(unsigned int mask);

bool Renderer_Init(vec2 viewportSize);
void Renderer_Update();
void Renderer_Exit();