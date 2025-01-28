#pragma once
#include "../DllCore.hpp"
#include <SDL3/SDL.h>
#include <string>
#include <utility>

namespace AuraEngine {
  class AE_API Window {
  public:
    Window();

    void Update();
    void SetSize(const std::pair<int, int> &size);
    void SetTitle(const std::string &title);

    SDL_Window *const GetSDLWindow();

    ~Window();
  private:
    SDL_Window *window = nullptr;
  };
} // namespace AuraEngine