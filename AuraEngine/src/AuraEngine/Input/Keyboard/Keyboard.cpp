#include "Keyboard.hpp"
#include "../../Log/Log.hpp"
#include <format>

namespace AuraEngine {
  Keyboard::Keyboard()
  {
    this->keyboardState = SDL_GetKeyboardState(nullptr);
  }

  bool Keyboard::KeyPressed(SDL_Scancode scancode) const
  {
    return this->keyboardState[scancode];
  }

}