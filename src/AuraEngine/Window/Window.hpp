#pragma once
#include "AuraEngine/AE_API.hpp"
#include <string_view>
#include <tuple>
#include <SDL3/SDL.h>

namespace AuraEngine
{
  class Window
  {
  public:
    Window(const std::tuple<int, int> &size, std::string_view title);

    void Update();

    SDL_Window *const GetHandle() const
    {
      return m_handle;
    }

    bool ShouldExit() const;

    AE_API ~Window();

  private:
    SDL_Window *m_handle = nullptr;
    SDL_GLContext m_glContext;
    bool m_shouldExit = false;
  };
} // namespace AuraEngine