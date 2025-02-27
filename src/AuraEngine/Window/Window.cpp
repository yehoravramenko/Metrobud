#include "Window.hpp"
#include "Debug/Debug.hpp"
#include "glad/glad.h"

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
    glfwTerminate();
    Debug::Error("Failed to create GLFW window");
  }

  glfwMakeContextCurrent(this->handle);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    glfwTerminate();
    Debug::Error("Failed to load GLAD");
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