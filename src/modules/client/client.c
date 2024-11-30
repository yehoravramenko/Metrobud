#include "client.h"
#include <modules/window/window.h>
#include <modules/renderer/renderer.h>

Client client;

Client g_Client() {
  return client;
}

void Client_Init() {
  client = calloc(1, sizeof(_Client));

  Window_Init(&(client->windowSize));
  DEBUG_MSG("window size is %f, %f", client->windowSize.x,
            client->windowSize.y);

  if (!Renderer_Init(client->windowSize)) {
    glfwTerminate();
    ERR_MSG("Failed to initialize OpenGL Renderer");
  }

  client->isRunning = true;
}

void Client_Update() {
  Window_Update(&(client->isRunning));
  Renderer_Update();
}

void Client_Exit() {
  free(client);
}
