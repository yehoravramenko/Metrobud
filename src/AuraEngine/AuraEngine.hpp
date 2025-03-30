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

    friend Application;

  private:
    std::tuple<int, int> windowSize;
    bool shouldExit = false;

    std::unique_ptr<Window> window = nullptr;
    std::unique_ptr<Renderer> renderer = nullptr;
    Application *application = nullptr;
  };
} // namespace AuraEngine