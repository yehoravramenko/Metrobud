#include "Client.hpp"

namespace AuraEngine {
  Client::Client(std::string_view name)
    : eventHandler(this), Debug() {
    this->Renderer = new AuraEngine::Renderer(this);
    this->Input = new AuraEngine::Input();

    this->name = name;
  }

  void Client::MainLoop()
  {
    this->OnStart();

    uint64_t now = SDL_GetTicks();
    uint64_t last = 0;
    while (this->isRunning)
    {
      last = now;
      now = SDL_GetTicks();
      deltaTime = static_cast<float>(now - last) / 1000;

      this->eventHandler.PollEvents();

      this->Renderer->Update();
      this->OnUpdate();

      Renderer->Render();
      this->OnRender();
    }
    this->OnExit();
  }

  const float &Client::GetDeltaTime() const
  {
    return this->deltaTime;
  }

  Client::~Client()
  {
    delete this->Renderer;
    delete this->Input;
  }
} // namespace AuraEngine