#include "Client.hpp"
#include "../Log/Log.hpp"

namespace AuraEngine {
  Client::Client(std::string_view name)
    : eventHandler(this), Debug() {
    this->Renderer = new AuraEngine::Renderer();
    this->Input = new AuraEngine::Input();

    this->name = name;
  }

  void Client::MainLoop()
  {
    this->OnStart();
    while (this->isRunning)
    {
      this->eventHandler.PollEvents();

      this->Renderer->Update();
      this->OnUpdate();

      Renderer->Render();
      this->OnRender();
    }
    this->OnExit();
  }

  Client::~Client()
  {
    delete this->Renderer;
    delete this->Input;
  }
} // namespace AuraEngine