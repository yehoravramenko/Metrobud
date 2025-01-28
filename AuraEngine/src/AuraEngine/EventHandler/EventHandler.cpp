#include "EventHandler.hpp"
#include <SDL3/SDL.h>

namespace AuraEngine {
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
      }
    }
  }
  bool EventHandler::ShouldQuit() const
  {
    return this->shouldQuit;
  }
}