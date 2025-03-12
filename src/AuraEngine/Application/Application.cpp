#include "Application.hpp"
namespace AuraEngine {
Application::Application(AuraEngine::Engine *engine) {
  m_engine                = engine;
  m_engine->m_application = this;
}

void Application::Exit() {
  m_engine->m_shouldExit = true;
}
} // namespace AuraEngine