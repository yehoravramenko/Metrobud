#include "MouseInput.hpp"
#include <SDL3/SDL_mouse.h>

namespace AuraEngine::MouseInput
{
  bool GetMouseButton(const MouseButton mouseButton)
  {
    return SDL_GetMouseState(nullptr, nullptr) & static_cast<unsigned char>(mouseButton);
  }

  const std::tuple<float, float> GetCursorPosition()
  {
    float mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    return std::tuple<float, float>{mouseX, mouseY};
  }
}