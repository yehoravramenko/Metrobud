#include "Window.hpp"
#include "../Log/Log.hpp"
#include <format>

namespace AuraEngine
{
  Window::Window()
  {
    this->window = SDL_CreateWindow("Aura Engine", 800, 600, SDL_WINDOW_OPENGL);

    int numDisplays = 0;
    SDL_DisplayID *displays = SDL_GetDisplays(&numDisplays);
    const SDL_DisplayMode *DM = SDL_GetCurrentDisplayMode(displays[0]);
    size = { DM->w, DM->h };
    Log::EngineLog.Info(std::format("Screen size: {}x{}", size.first, size.second));

    SDL_SetWindowSize(this->window, this->size.first, this->size.second);
    SDL_SetWindowFullscreen(this->window, true);

    if (!this->window)
      Log::EngineLog.Error(std::string("Failed to create window.\nSDL_Error: ") + SDL_GetError());
  }

  void Window::Update()
  {
    SDL_GL_SwapWindow(this->window);
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