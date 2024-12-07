#pragma once

#include <common.hpp>
#include "wrapper/buffer.hpp"
#include "wrapper/vertexarray.hpp"
#include "wrapper/shader.hpp"
#include "wrapper/opengl.hpp"

// typedef struct Renderer {
//   unsigned int clearMask;

//   Buffer VBO;
//   VertexArray VAO;
// } Renderer;

// Renderer *g_Renderer();

// void Renderer_SetClearMask(unsigned int mask);

// bool Renderer_Init(vec2 viewportSize);
// void Renderer_Update();
// void Renderer_Render();
// void Renderer_Exit();

class Renderer {
public:
  unsigned int clearMask;
  vec4 clearColor;

  VertexArray *VAO;
  Buffer *VBO;

  Renderer(vec2 &viewportSize);
  void Update();
  void Render();
  ~Renderer();
};