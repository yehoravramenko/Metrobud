#include "AuraEngine.hpp"
#include "Application/Application.hpp"
#include "Debug/Debug.hpp"

namespace AuraEngine
{
  Engine::Engine()
  {
    this->timeLast = 0;
    this->timeNow = SDL_GetPerformanceCounter();

    this->window = std::make_unique<Window>("Metrobud");

    this->renderer = std::make_unique<Renderer>(this->window->GetSize());
  }

  const float Engine::GetDeltaTime() const
  {
    return (this->timeNow - this->timeLast) / static_cast<float>(SDL_GetPerformanceFrequency());
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

    this->timeLast = this->timeNow;
    this->timeNow = SDL_GetPerformanceCounter();

    this->window->Update();
    this->renderer->Update();

    this->application->OnUpdate();

    this->renderer->Draw();

    this->application->OnDraw();
  }
} // namespace AuraEngine