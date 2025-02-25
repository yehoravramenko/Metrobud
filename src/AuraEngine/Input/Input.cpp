#include "Input.hpp"
#include "Debug/Debug.hpp"

namespace AuraEngine {
GLFWwindow *Input::g_glfwWindow = nullptr;

bool Input::GetKey(const KeyCode keycode) {
  if (g_glfwWindow == nullptr) {
    Debug::Warning("Input::GetKey() => Native window is not set");
    return false;
  }
  return KeyboardInput::GetKeyState(g_glfwWindow, keycode) == KeyState::Press;
}

bool Input::GetKeyRelease(const KeyCode keycode) {
  if (g_glfwWindow == nullptr) {
    Debug::Warning("Input::GetKeyRelease() => Native window is not set");
    return false;
  }
  return KeyboardInput::GetKeyState(g_glfwWindow, keycode) == KeyState::Release;
}
} // namespace AuraEngine