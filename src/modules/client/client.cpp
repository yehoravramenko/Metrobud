#define DEBUG_LOG
#include "client.hpp"
#include <modules/window/window.hpp>
#include <modules/renderer/renderer.hpp>

Window *window;
Renderer *renderer;

void Client::Init() {
#ifndef DEBUG
  Engine_InitLog();
  DEBUG_MSG("METROBUD LOG\nLog started\n\n");
#endif

  window = new Window();
  DEBUG_MSG("window size is %f, %f", window->size.x, window->size.y);

  renderer = new Renderer(window->size);

  Client::isRunning = true;
}

void Client::Update() {
  window->Update(Client::isRunning);
  renderer->Update();
  renderer->Render();
}

void Client::Exit() {
  delete window;
  delete renderer;
}
