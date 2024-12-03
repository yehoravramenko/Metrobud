#include "renderer.h"

float vertices[] = {
    // positions          // texture coords
    0.5f,  0.5f,  0.0f, 1.0f, 1.0f, // top right
    0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f,  0.0f, 0.0f, 1.0f  // top left
};

Renderer *renderer;

Renderer *g_Renderer() {
  return renderer;
}

void Renderer_SetClearColor(float R, float G, float B, float A) {
  glClearColor(R, G, B, A);
}

void Renderer_SetClearMask(unsigned int mask) {
  renderer->clearMask = mask;
}

bool Renderer_Init(vec2 viewportSize) {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    ERR_MSG("Failed to initialize OpenGL");
  }

  renderer = calloc(1, sizeof(Renderer));
  Renderer_SetClearColor(0.0f, 0.5f, 0.0f, 0.0f);
  Renderer_SetClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glViewport(0, 0, viewportSize.x, viewportSize.y);

  Buffer_Generate(&renderer->VBO, GL_ARRAY_BUFFER);
  Buffer_Data(&renderer->VBO, sizeof(vertices), vertices, GL_STATIC_DRAW);

  return true;
}

void Renderer_Update() {
  glClear(renderer->clearMask);
}

void Renderer_Exit() {
  Buffer_Free(&renderer->VBO);
  free(renderer);
}
