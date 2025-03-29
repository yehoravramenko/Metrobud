#include "AuraEngine.hpp"
#include "Application/Application.hpp"
#include "AuraEngine/Debug/Debug.hpp"

namespace AuraEngine
{
  Engine::Engine()
  {
    m_windowSize = std::tuple(1280, 720);
    m_window = std::make_unique<Window>(m_windowSize, "Metrobud");

    m_renderer = std::make_unique<Renderer>(m_windowSize);
  }

  void Engine::EventLoop()
  {
    if(m_application == nullptr)
    {
      Debug::Error("No application class provided to engine");
    }

    if(m_window->ShouldExit())
    {
      m_shouldExit = true;
    }

    m_window->Update();
    m_renderer->Update();

    m_application->OnUpdate();

    m_renderer->Draw();

    m_application->OnDraw();
  }
} // namespace AuraEngine