#include "EventHandler.hpp"
#include "../Client/Client.hpp"
#include "../Log/Log.hpp"
#include <SDL3/SDL.h>
#include "../UI/UI.hpp"

namespace AuraEngine {
  EventHandler::EventHandler(Client *const client)
  {
    this->client = client;
  }
  void EventHandler::PollEvents()
  {
    SDL_Event event = { 0 };
    while (SDL_PollEvent(&event))
    {
      this->client->Renderer->ui->ProcessSDLEvent(event);
      switch (event.type)
      {
      case SDL_EVENT_QUIT:
        this->client->isRunning = false;
        break;
      case SDL_EVENT_WINDOW_RESIZED:
        this->client->Renderer->windowResizeCallback({ event.window.data1, event.window.data2 });
        break;

      case SDL_EVENT_KEY_DOWN:
        if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
          this->client->isRunning = false;
        }
        Log::EngineLog.Info(std::format("Key pressed: {}", SDL_GetKeyName(event.key.key)));
        break;
      case SDL_EVENT_KEY_UP:
        Log::EngineLog.Info(std::format("Key released: {}", SDL_GetKeyName(event.key.key)));
        break;
      }
    }
  }

  EventHandler::~EventHandler()
  {
  }
}