#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <string_view>
#include <tuple>

namespace Metrobud {
class Window
{
public:
  Window(const std::tuple<int, int> size, std::string_view title);

private:
  static bool glfwInitialized;

  GLFWwindow* handle = nullptr;
};
}