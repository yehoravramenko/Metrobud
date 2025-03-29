#pragma once
#include "AuraEngine/AE_API.hpp"
#include "KeyboardInput/KeyboardInput.hpp"

namespace AuraEngine
{
  namespace Input
  {
    AE_API bool GetKey(const KeyCode keycode);
    AE_API bool GetKeyRelease(const KeyCode keycode);

    // bool GetMouseButton(); // TODO
  }

  /*namespace InputNativeAPI
  {
    SDL_Window *g_sdlWindow;
  }*/
}
