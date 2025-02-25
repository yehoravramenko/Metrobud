#include "KeyboardInput.hpp"

namespace AuraEngine::KeyboardInput {
KeyState GetKeyState(GLFWwindow *window, const KeyCode keycode) {
  return static_cast<KeyState>(glfwGetKey(window, keycode));
}
} // namespace AuraEngine::KeyboardInput