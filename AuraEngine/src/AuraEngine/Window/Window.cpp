#include "Window.hpp"
#include "../Log/Log.hpp"

namespace AuraEngine
{
  Window::Window()
  {
    Log::EngineLog.Info("Window called");

    this->window = SDL_CreateWindow("Aura Engine", 800, 600, SDL_WINDOW_OPENGL);

    if (!this->window)
      Log::EngineLog.Error(std::string("Failed to create window.\nSDL_Error: ") + SDL_GetError());
  }

  void Window::Update()
  {
    SDL_GL_SwapWindow(this->window);
  }

  void Window::SetSize(const std::pair<int, int> &size)
  {
    SDL_SetWindowSize(this->window, size.first, size.second);
  }

  void Window::SetTitle(const std::string &title)
  {
    SDL_SetWindowTitle(this->window, title.c_str());
  }

  SDL_Window *const Window::GetSDLWindow()
  {
    return this->window;
  }

  Window::~Window()
  {

  }
}