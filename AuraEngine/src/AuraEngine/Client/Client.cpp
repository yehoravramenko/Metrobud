#include "Client.hpp"
#include "../Log/Log.hpp"

namespace AuraEngine {
  Client::Client(const std::string &name = "") {
    Log::EngineLog.Info("Client called");
    this->Renderer = new AuraEngine::Renderer();
    this->eventHandler = new EventHandler(this->Renderer);
    this->Input = new AuraEngine::Input();
  }

  void Client::MainLoop()
  {
    this->OnStart();
    while (this->isRunning)
    {
      this->eventHandler->PollEvents();

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
    delete this->eventHandler;
    delete this->Input;
  }
} // namespace AuraEngine