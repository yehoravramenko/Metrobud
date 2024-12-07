#define DEBUG_LOG
#include "client.h"
#include <modules/window/window.h>
#include <modules/renderer/renderer.h>

Client *client;

Client *g_Client() {
  return client;
}

void Client_Init() {
#ifndef DEBUG
  Engine_InitLog();
  DEBUG_MSG("METROBUD LOG\nLog started\n\n");
#endif

  client = calloc(1, sizeof(Client));

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
  Renderer_Render();
}

void Client_Exit() {
  Renderer_Exit();
  free(client);
}
