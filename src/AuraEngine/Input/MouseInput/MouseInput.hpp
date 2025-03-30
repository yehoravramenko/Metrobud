#pragma once
#include <tuple>


namespace AuraEngine
{
  enum class MouseButton
  {
    Left = 0x01,
    Middle = 0x02,
    Right = 0x04,
  };

  namespace MouseInput
  {
    bool GetMouseButton(const MouseButton mouseButton);
    const std::tuple<float, float> GetCursorPosition();
  }
}