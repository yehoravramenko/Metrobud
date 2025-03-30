#include "Input.hpp"
#include "Debug/Debug.hpp"

namespace AuraEngine
{
  bool Input::GetKey(const KeyCode keycode)
  {
    return KeyboardInput::GetKeyState(keycode) == KeyState::Pressed;
  }

  bool Input::GetKeyRelease(const KeyCode keycode)
  {
    return KeyboardInput::GetKeyState(keycode) == KeyState::Released;
  }

  bool Input::GetMouseButton(const MouseButton mouseButton)
  {
    return MouseInput::GetMouseButton(mouseButton);
  }

  const std::tuple<float, float> Input::GetCursorPosition()
  {
    return MouseInput::GetCursorPosition();
  }

} // namespace AuraEngine