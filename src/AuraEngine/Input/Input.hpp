#pragma once
#include "KeyboardInput/KeyboardInput.hpp"
#include "MouseInput/MouseInput.hpp"

/*namespace AuraEngine
{
  //namespace Input
  //{
    /*AE_API bool GetKey(const KeyCode keycode);
    AE_API bool GetKeyRelease(const KeyCode keycode);

    AE_API bool GetMouseButton(const MouseButton mouseButton);
    AE_API const std::tuple<float, float> GetCursorPosition();
    //}
}*/

struct SDL_Window;

namespace AuraEngine::InputNativeAPI
{
  extern SDL_Window *NativeWindow;
}