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

  int Application::GetWindowWidth() const
  {
    return this->engine->windowSize.width;
  }
  int Application::GetWindowHeight() const
  {
    return this->engine->windowSize.height;
  }

  const float Application::GetDeltaTime() const
  {
    return this->engine->GetDeltaTime();
  }
} // namespace AuraEngine