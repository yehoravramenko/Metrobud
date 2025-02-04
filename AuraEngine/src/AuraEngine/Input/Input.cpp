#include "Input.hpp"

namespace AuraEngine
{
  AE_API bool Input::GetKey(Keycode keycode) const
  {
    return this->keyboard.KeyPressed(static_cast<SDL_Scancode>(keycode));
  }
}