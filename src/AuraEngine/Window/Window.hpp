#pragma once
#include "AE_API.hpp"
#include <string_view>
#include <SDL3/SDL.h>

namespace AuraEngine
{
  struct WindowSize
  {
    int width, height;
  };

  class Window
  {
  public:
    Window(std::string_view title, WindowSize size = { 0,0 });

    void Update();

    const WindowSize &GetSize() const;

    SDL_Window *const GetHandle() const
    {
      return this->handle;
    }

    bool ShouldExit() const;

    AE_API ~Window();

  private:
    WindowSize size;
    SDL_Window *handle = nullptr;
    SDL_GLContext glContext;
    bool shouldExit = false;
  };
} // namespace AuraEngine