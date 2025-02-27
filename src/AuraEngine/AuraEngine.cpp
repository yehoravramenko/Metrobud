#include "AuraEngine.hpp"
#include "Application/Application.hpp"
#include "Debug/Debug.hpp"

namespace AuraEngine {
Engine::Engine() {
  this->size   = std::tuple(1280, 720);
  this->window = std::make_unique<Window>(this->size, "Metrobud");
  // this->renderer      = std::make_unique<Renderer>(this->size);
  this->renderer      = std::make_unique<Renderer>(this->size);
  Input::g_glfwWindow = this->window->GetHandle();
}
void Engine::EventLoop() {
  if (this->application == nullptr) {
    Debug::Error("No application class provided to engine");
  }
  if (this->window->ShouldExit())
    this->shouldExit = true;

  this->window->Update();
  this->renderer->Update();

  this->application->OnUpdate();

  this->renderer->Draw();

  this->application->OnDraw();
}
} // namespace AuraEngine