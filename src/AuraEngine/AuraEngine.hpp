#pragma once
#include "AE_API.hpp"
#include "Input/Input.hpp"
#include "Renderer/Renderer.hpp"
#include "Window/Window.hpp"
#include <memory>

namespace AuraEngine
{
  class Application;

  class Engine
  {
  public:
    AE_API Engine();
    AE_API void EventLoop();

    bool ShouldExit() const
    {
      return this->shouldExit;
    }

    const float GetDeltaTime() const;

    friend Application;

  private:
    bool shouldExit = false;

    Uint64 timeNow, timeLast;

    std::unique_ptr<Window> window = nullptr;
    std::unique_ptr<Renderer> renderer = nullptr;
    Application *application = nullptr;
  };
} // namespace AuraEngine