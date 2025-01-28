#pragma once
#include "../DllCore.hpp"
#include "../Window/Window.hpp"
#include <SDL3/SDL.h>

namespace AuraEngine {
  class EventHandler;
  class AE_API Renderer {
  public:
    Renderer();
    void Render();

    Window *const GetWindow();

    ~Renderer();

    friend EventHandler;

  private:
    Window *window = nullptr;
    SDL_GLContext gl_context = nullptr;

    void windowResizeCallback(std::pair<int, int> newSize);
  };
} // namespace AuraEngine