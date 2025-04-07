#include "Application.hpp"
namespace AuraEngine
{
  Application::Application(AuraEngine::Engine *engine)
  {
    this->engine = engine;
    this->engine->application = this;
    this->mainCamera = this->engine->renderer->GetMainCamera();
  }

  void Application::Exit()
  {
    this->engine->shouldExit = true;
  }

  const WindowSize &Application::GetWindowSize() const
  {
    return this->engine->window->GetSize();
  }

  const float Application::GetDeltaTime() const
  {
    return this->engine->GetDeltaTime();
  }
} // namespace AuraEngine