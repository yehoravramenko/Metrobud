#pragma once
#include "../DllCore.hpp"
#include "../Renderer/Renderer.hpp"
#include "../EventHandler/EventHandler.hpp"

namespace AuraEngine {
  class AE_API Client {
  public:
    Client();

    void MainLoop();

    virtual void OnStart() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;
    virtual void OnExit() = 0;

    ~Client();

    friend EventHandler;

  protected:
    Renderer *renderer = nullptr;
    EventHandler *eventHandler = nullptr;

  private:

  };
} // namespace AuraEngine