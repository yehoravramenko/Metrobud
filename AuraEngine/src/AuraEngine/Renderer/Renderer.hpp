#pragma once
#include "../DllCore.hpp"
#include "../Window/Window.hpp"
#include <SDL3/SDL.h>
#include "Buffer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

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

    Buffer *VBO = nullptr;
    Buffer *EBO = nullptr;
    VertexArray *DummyVAO = nullptr;
    Shader *shader = nullptr;
    Texture *texture1 = nullptr;

    void windowResizeCallback(std::pair<int, int> newSize);
  };
} // namespace AuraEngine