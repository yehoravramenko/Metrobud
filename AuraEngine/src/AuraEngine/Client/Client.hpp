#pragma once
#include "../ExportAPI.hpp"
#include "../Renderer/Renderer.hpp"
#include "../Debug/Debug.hpp"
#include "../EventHandler/EventHandler.hpp"
#include "../Input/Input.hpp"
#include <string>

namespace AuraEngine {
  class Client {
  public:
    AE_API Client(std::string_view name = "");

    AE_API void MainLoop();

    virtual void OnStart() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;
    virtual void OnExit() = 0;

    AE_API const float &GetDeltaTime() const;

    AE_API ~Client();

    friend EventHandler;

  protected:
    const Input *Input = nullptr;
    const Renderer *Renderer = nullptr;
    const Debug Debug;

  private:
    EventHandler eventHandler;

    float deltaTime = 0.0f;

    bool isRunning = true;
    std::string name = "Aura Engine";
  };
} // namespace AuraEngine