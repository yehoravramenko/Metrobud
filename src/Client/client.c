#include "client.h"
#include "../Renderer/renderer.h"

const int W_WIDTH = 800;
const int W_HEIGHT = 600;

AuraClient client;

AuraClient Client() {
  return client;
}

void Client_Init() {
  client = calloc(1, sizeof(_AuraClient));
  if (!glfwInit()) {
    ERR_MSG("Failed to initialize GLFW");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  client->window = glfwCreateWindow(W_WIDTH, W_HEIGHT, "metrobud", NULL, NULL);

  if (client->window == NULL) {
    glfwTerminate();
    ERR_MSG("Failed to create a window");
  }

  glfwMakeContextCurrent(client->window);

  if (!Renderer_Init(W_WIDTH, W_HEIGHT)) {
    glfwTerminate();
    ERR_MSG("Failed to initialize OpenGL Renderer");
  }

  client->isRunning = true;
}

void Client_Update() {
  if (glfwGetKey(client->window, GLFW_KEY_ESCAPE) == GLFW_PRESS ||
      glfwWindowShouldClose(client->window))
    client->isRunning = false;

  Renderer_Update();

  glfwSwapBuffers(client->window);
  glfwPollEvents();
}

void Client_Exit() {
  free(client);
}
