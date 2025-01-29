#pragma once
#include "../DllCore.hpp"
#include "../Window/Window.hpp"
#include <SDL3/SDL.h>
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"

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

    VertexBuffer *VBO = nullptr;
    VertexArray *DummyVAO = nullptr;
    Shader *shader = nullptr;

    void windowResizeCallback(std::pair<int, int> newSize);
  };
} // namespace AuraEngine