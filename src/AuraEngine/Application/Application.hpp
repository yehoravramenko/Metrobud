#pragma once
#include "AE_API.hpp"
#include "Renderer/Camera.hpp"
#include "../AuraEngine.hpp"
#include "../Input/Input.hpp"

namespace AuraEngine
{
  class Application
  {
  public:
    AE_API Application(AuraEngine::Engine *engine);

    virtual void OnStart() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnDraw() = 0;
    virtual void OnExit() = 0;

    virtual ~Application() = default;

  protected:
    Camera *mainCamera = nullptr;

    AE_API virtual void Exit() final;

  private:
    AuraEngine::Engine *engine;
  };
} // namespace AuraEngine