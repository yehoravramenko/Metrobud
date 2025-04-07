#pragma once
#include "AE_API.hpp"
#include "Math.hpp"

namespace AuraEngine
{
  enum class MouseButton
  {
    Left = 0x01,
    Middle = 0x02,
    Right = 0x04,
  };

  namespace Input
  {
    AE_API bool GetMouseButton(const MouseButton mouseButton);

    AE_API const Vector2 GetCursorPosition();
    AE_API void SetCursorVisibility(const bool visible);
    AE_API void SetCursorPosition(const float x, const float y);
    AE_API void SetCursorPosition(const Vector2 &position);
  }
}