#include "Window.hpp"
#include "../Log/Log.hpp"

namespace AuraEngine
{
  Window::Window()
  {
    Log::EngineLog.Info("Window called");

    this->window = SDL_CreateWindow("Aura Engine", this->size.first, this->size.second, SDL_WINDOW_OPENGL);

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
    this->size = size;
  }

  void Window::SetTitle(const std::string &title)
  {
    SDL_SetWindowTitle(this->window, title.c_str());
  }

  SDL_Window *const Window::GetSDLWindow()
  {
    return this->window;
  }

  const std::pair<int, int> &Window::GetSize()
  {
    return this->size;
  }

  Window::~Window()
  {

  }
}