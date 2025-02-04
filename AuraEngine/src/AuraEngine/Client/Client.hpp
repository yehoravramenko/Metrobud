#pragma once
#include "../ExportAPI.hpp"
#include "../Renderer/Renderer.hpp"
#include "../EventHandler/EventHandler.hpp"
#include "../Input/Input.hpp"
#include <string>

namespace AuraEngine {
  class AE_API Client {
  public:
    Client(const std::string &name = "");

    void MainLoop();

    virtual void OnStart() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;
    virtual void OnExit() = 0;

    ~Client();

    friend EventHandler;

  protected:
    const Input *Input = nullptr;
    const Renderer *Renderer = nullptr;

  private:
    EventHandler *eventHandler = nullptr;

    bool isRunning = true;
    std::string name = "Aura Engine";
  };
} // namespace AuraEngine