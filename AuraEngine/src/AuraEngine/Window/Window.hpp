#pragma once
#include "../ExportAPI.hpp"
#include <SDL3/SDL.h>
#include <string>
#include <utility>

namespace AuraEngine {
  class Window {
  public:
    Window();

    void Update();
    AE_API void SetSize(const std::pair<int, int> &size);
    AE_API void SetTitle(const std::string &title);

    SDL_Window *const GetSDLWindow();

    const std::pair<int, int> &GetSize();

    ~Window();
  private:
    SDL_Window *window = nullptr;
    std::pair<int, int> size = { 800, 600 };
  };
} // namespace AuraEngine