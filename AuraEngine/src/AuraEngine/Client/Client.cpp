#include "Client.hpp"
#include "../Log/Log.hpp"
//#define GLFW_INCLUDE_NONE
//#include "GLFW/glfw3.h"

namespace AuraEngine {
  Client::Client() {
    Log::EngineLog.Info("Client called");
    this->renderer = new Renderer();
    this->eventHandler = new EventHandler();
  }

  void Client::MainLoop()
  {
    this->OnStart();
    while (!this->eventHandler->ShouldQuit())
    {
      this->eventHandler->PollEvents();

      this->renderer->GetWindow()->Update();
      this->OnUpdate();

      renderer->Render();
      this->OnRender();
    }
    this->OnExit();
  }

  Client::~Client()
  {
    delete this->renderer;
    delete this->eventHandler;
  }

} // namespace AuraEngine