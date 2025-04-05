#include "MouseInput.hpp"
#include "Input/Input.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_mouse.h>

namespace AuraEngine::Input
{
  bool GetMouseButton(const MouseButton mouseButton)
  {
    return SDL_GetMouseState(nullptr, nullptr) & static_cast<unsigned char>(mouseButton);
  }

  const Vector2 GetCursorPosition()
  {
    float mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    return Vector2{ mouseX, mouseY };
  }

  void SetCursorVisibility(const bool visible)
  {
    if(visible)
    {
      SDL_ShowCursor();
      return;
    }
    SDL_HideCursor();
  }

  void SetCursorPosition(const float x, const float y)
  {
    SDL_WarpMouseInWindow(InputNativeAPI::NativeWindow, x, y);
  }
}