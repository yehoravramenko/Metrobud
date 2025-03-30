#include "Application.hpp"
namespace AuraEngine
{
  Application::Application(AuraEngine::Engine *engine)
  {
    this->engine = engine;
    this->engine->application = this;
  }

  void Application::Exit()
  {
    this->engine->shouldExit = true;
  }
} // namespace AuraEngine