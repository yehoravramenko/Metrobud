#pragma once
#include "../ExportAPI.hpp"
#include "../Window/Window.hpp"
#include "../EventHandler/EventHandler.hpp"
#include <SDL3/SDL.h>
#include "Buffer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

#include <utility>

namespace AuraEngine {
  class AE_API Renderer {
  public:
    Renderer();
    void Update() const;
    void Render() const;

    void SetSize(const std::pair<int, int> &size) const;

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