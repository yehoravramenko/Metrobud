#pragma once

#include "../common.h"

typedef struct ColorRGBA {
  float R, G, B, A;
} ColorRGBA;

typedef struct _AuraRenderer {
  ColorRGBA clearColor;
  unsigned int clearMask;

  unsigned int VAO;
  unsigned int VBO;
} _AuraRenderer;

typedef _AuraRenderer *AuraRenderer;

AuraRenderer Renderer();

void Renderer_SetClearColor(float R, float G, float B, float A);
void Renderer_SetClearMask(unsigned int mask);

bool Renderer_Init(int viewportWidth, int viewportHeight);
void Renderer_Update();
void Renderer_Exit();