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
#include <memory>

namespace AuraEngine {
  class EventHandler;
  class Client;
  class Renderer {
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
    SDL_GLContext gl_context = nullptr;

    std::unique_ptr<UI> ui;
    std::unique_ptr<Window> window;

    std::unique_ptr<Buffer> VBO;
    std::unique_ptr<Buffer> EBO;
    std::unique_ptr<VertexArray> DummyVAO;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Texture> texture1;
    std::unique_ptr<Camera> camera;

    void windowResizeCallback(std::pair<int, int> newSize) const;
  };
} // namespace AuraEngine