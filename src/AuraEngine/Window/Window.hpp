#pragma once
#include "GLFW/glfw3.h"
#include <string_view>
#include <tuple>

namespace AuraEngine {
class Window {
public:
  Window(const std::tuple<int, int> size, std::string_view title);

  void Update();

  GLFWwindow *GetHandle() {
    return m_handle;
  }

  bool ShouldExit() {
    return glfwWindowShouldClose(m_handle);
  }

  ~Window();

private:
  static bool m_glfwInitialized;

  GLFWwindow *m_handle = nullptr;
};
} // namespace AuraEngine