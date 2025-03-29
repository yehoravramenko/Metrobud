#include "KeyboardInput.hpp"
#include "..\..\Debug\Debug.hpp"
#include <SDL3\SDL_keyboard.h>

namespace AuraEngine::KeyboardInput
{
  KeyState GetKeyState(const KeyCode keycode)
  {
    const bool *keyStates = SDL_GetKeyboardState(nullptr);
    if(keyStates[keycode])
    {
      return KeyState::Pressed;
    }

    return KeyState::Released;
  }
} // namespace AuraEngine::KeyboardInput