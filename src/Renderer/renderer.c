#include "renderer.h"

float vertices[] = {
    // positions          // texture coords
    0.5f,  0.5f,  0.0f, 1.0f, 1.0f, // top right
    0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f,  0.0f, 0.0f, 1.0f  // top left
};

AuraRenderer renderer;

AuraRenderer Renderer() {
  return renderer;
}

void Renderer_SetClearColor(float R, float G, float B, float A) {
  renderer->clearColor.R = R;
  renderer->clearColor.G = G;
  renderer->clearColor.B = B;
  renderer->clearColor.A = A;
}

void Renderer_SetClearMask(unsigned int mask) {
  renderer->clearMask = mask;
}

bool Renderer_Init(int viewportWidth, int viewportHeight) {
  renderer = calloc(1, sizeof(_AuraRenderer));
  Renderer_SetClearColor(0.0f, 0.5f, 0.0f, 0.0f);
  Renderer_SetClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (!gladLoadGL())
    return false;
  glViewport(0, 0, viewportWidth, viewportHeight);
  glClearColor(renderer->clearColor.R, renderer->clearColor.G,
               renderer->clearColor.B, renderer->clearColor.A);

  return true;
}

void Renderer_Update() {
  glClear(renderer->clearMask);
}

void Renderer_Exit() {
  free(renderer);
}
