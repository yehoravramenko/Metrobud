#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <string_view>
#include <tuple>

namespace AuraEngine {
class Window {
public:
  Window(const std::tuple<int, int> size, std::string_view title);

  void Update();

  auto GetHandle() -> GLFWwindow * { return this->handle; }
  auto ShouldExit() -> bool { return glfwWindowShouldClose(this->handle); }

  ~Window();

private:
  static bool glfwInitialized;

  GLFWwindow *handle = nullptr;
};
} // namespace AuraEngine