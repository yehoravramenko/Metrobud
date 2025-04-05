#include "KeyboardInput.hpp"
#include "..\..\Debug\Debug.hpp"
#include <SDL3\SDL_keyboard.h>

namespace AuraEngine::Input
{
  KeyState GetKeyState(const KeyCode keycode)
  {
    const bool *keyStates = SDL_GetKeyboardState(nullptr);
    if(keyStates[static_cast<int>(keycode)])
    {
      return KeyState::Pressed;
    }

    return KeyState::Released;
  }

  bool GetKey(const KeyCode keycode)
  {
    return GetKeyState(keycode) == KeyState::Pressed;
  }

  bool GetKeyUp(const KeyCode keycode)
  {
    return GetKeyState(keycode) == KeyState::Released;
  }

} // namespace AuraEngine::KeyboardInput