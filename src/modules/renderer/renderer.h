#pragma once

#include <common.h>
#include "vertexbuffer.h"

typedef struct _Renderer {
  unsigned int clearMask;

  VertexBuffer VBO;
  unsigned int VAO;
} _Renderer;

typedef _Renderer *Renderer;

Renderer g_Renderer();

void Renderer_SetClearColor(float R, float G, float B, float A);
void Renderer_SetClearMask(unsigned int mask);

bool Renderer_Init(vec2 viewportSize);
void Renderer_Update();
void Renderer_Exit();