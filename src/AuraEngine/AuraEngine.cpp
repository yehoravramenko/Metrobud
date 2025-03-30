#include "AuraEngine.hpp"
#include "Application/Application.hpp"
#include "Debug/Debug.hpp"

namespace AuraEngine
{
  Engine::Engine()
  {
    this->windowSize = std::tuple(1280, 720);
    this->window = std::make_unique<Window>(this->windowSize, "Metrobud");

    this->renderer = std::make_unique<Renderer>(this->windowSize);
  }

  void Engine::EventLoop()
  {
    if(this->application == nullptr)
    {
      Debug::Error("No application class provided to engine");
    }

    if(this->window->ShouldExit())
    {
      this->shouldExit = true;
    }

    this->window->Update();
    this->renderer->Update();

    this->application->OnUpdate();

    this->renderer->Draw();

    this->application->OnDraw();
  }
} // namespace AuraEngine