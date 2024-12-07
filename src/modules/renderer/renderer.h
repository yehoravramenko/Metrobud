#pragma once

#include <common.h>
#include "wrapper/buffer.h"
#include "wrapper/vertexarray.h"
#include "wrapper/shader.h"
#include "wrapper/opengl.h"

typedef struct Renderer {
  unsigned int clearMask;

  Buffer VBO;
  VertexArray VAO;
} Renderer;

Renderer *g_Renderer();

void Renderer_SetClearMask(unsigned int mask);

bool Renderer_Init(vec2 viewportSize);
void Renderer_Update();
void Renderer_Render();
void Renderer_Exit();