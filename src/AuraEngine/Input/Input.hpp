#pragma once
#include "KeyboardInput/KeyboardInput.hpp"
#include "MouseInput/MouseInput.hpp"

struct SDL_Window;

namespace AuraEngine::InputNativeAPI
{
  extern SDL_Window *NativeWindow;
}