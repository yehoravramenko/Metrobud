#pragma once
#include "KeyboardInput/KeyboardInput.hpp"

namespace AuraEngine {
class Engine;
class Input {
public:
  static bool GetKey(const KeyCode keycode);
  static bool GetKeyRelease(const KeyCode keycode);

  static bool GetMouseButton(); // TODO

  friend Engine;

private:
  static GLFWwindow *g_glfwWindow;
};
} // namespace AuraEngine