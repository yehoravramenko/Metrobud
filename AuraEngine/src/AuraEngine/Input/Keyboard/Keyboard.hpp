#pragma once
#include "../../ExportAPI.hpp"
#include <SDL3/SDL.h>

namespace AuraEngine
{
  class Keyboard
  {
  public:
    Keyboard();
    AE_API bool KeyPressed(SDL_Scancode scancode) const;

  private:
    const bool *keyboardState;
  };
}