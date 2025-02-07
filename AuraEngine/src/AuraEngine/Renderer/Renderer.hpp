#pragma once
#include "../ExportAPI.hpp"
#include "../Window/Window.hpp"
#include "../UI/UI.hpp"
#include <SDL3/SDL.h>
#include "Buffer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Camera.hpp"

#include <utility>

namespace AuraEngine {
  class EventHandler;
  class Client;
  class AE_API Renderer {
  public:
    Renderer(Client *client);
    void Update() const;
    void Render() const;

    //void SetSize(const std::pair<int, int> &size) const;
    const float GetAspectRatio() const;
    Camera *const GetCamera() const;

    ~Renderer();

    friend EventHandler;

  private:
    const Client *client = nullptr;
    Window *window = nullptr;
    SDL_GLContext gl_context = nullptr;
    UI *ui = nullptr;

    Buffer *VBO = nullptr;
    Buffer *EBO = nullptr;
    VertexArray *DummyVAO = nullptr;
    Shader *shader = nullptr;
    Texture *texture1 = nullptr;
    Camera *camera = nullptr;

    void windowResizeCallback(std::pair<int, int> newSize) const;
  };
} // namespace AuraEngine