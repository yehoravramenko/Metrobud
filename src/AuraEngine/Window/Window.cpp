#include "Window.hpp"
#include "Debug/Debug.hpp"

namespace AuraEngine {
Window::Window(const std::tuple<int, int> size, std::string_view title) {
  auto res = glfwInit();
  if (!res) {
    Debug::Error("Failed to initialize GLFW");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  this->handle = glfwCreateWindow(std::get<0>(size), std::get<1>(size),
                                  title.data(), nullptr, nullptr);
  if (handle == nullptr) {
    Debug::Error("Failed to create GLFW window");
  }
}

void Window::Update() {
  glfwPollEvents();
  glfwSwapBuffers(this->handle);
}

Window::~Window() {
  glfwDestroyWindow(this->handle);
  glfwTerminate();
}
} // namespace AuraEngine