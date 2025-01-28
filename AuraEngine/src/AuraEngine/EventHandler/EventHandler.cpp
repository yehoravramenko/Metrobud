#include "EventHandler.hpp"
#include <SDL3/SDL.h>

namespace AuraEngine {
  EventHandler::EventHandler(Renderer *const renderer)
  {
    this->renderer = renderer;
  }
  void EventHandler::PollEvents()
  {
    SDL_Event event = { 0 };
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_EVENT_QUIT:
        this->shouldQuit = true;
        break;
      case SDL_EVENT_WINDOW_RESIZED:
        this->renderer->windowResizeCallback({ event.window.data1, event.window.data2 });
        break;
      }
    }
  }
  bool EventHandler::ShouldQuit() const
  {
    return this->shouldQuit;
  }
}