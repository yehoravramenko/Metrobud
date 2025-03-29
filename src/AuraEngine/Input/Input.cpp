#include "Input.hpp"
#include "AuraEngine/Debug/Debug.hpp"

namespace AuraEngine
{
  bool Input::GetKey(const KeyCode keycode)
  {
    /*if(g_sdlWindow == nullptr)
    {
      Debug::Warning("Input::GetKey() => Native window is not set");
      return false;
    }*/
    return KeyboardInput::GetKeyState(keycode) == KeyState::Pressed;
  }

  bool Input::GetKeyRelease(const KeyCode keycode)
  {
    return KeyboardInput::GetKeyState(keycode) == KeyState::Released;
  }
} // namespace AuraEngine