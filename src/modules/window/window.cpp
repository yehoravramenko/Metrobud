#include "window.hpp"

const int W_WIDTH = 800;
const int W_HEIGHT = 600;

Window::Window() {
  if (!glfwInit()) {
    ERR_MSG("Failed to initialize GLFW");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  this->pGLFWwindow =
      glfwCreateWindow(W_WIDTH, W_HEIGHT, "metrobud", NULL, NULL);

  if (this->pGLFWwindow == nullptr) {
    glfwTerminate();
    ERR_MSG("Failed to create a window");
  }

  glfwMakeContextCurrent(this->pGLFWwindow);

  size = {W_WIDTH, W_HEIGHT};
}

void Window::Update(bool &isRunning) {
  if (glfwGetKey(this->pGLFWwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS ||
      glfwWindowShouldClose(this->pGLFWwindow)) {
    isRunning = false;
  }

  glfwSwapBuffers(this->pGLFWwindow);
  glfwPollEvents();
}

Window::~Window() {
  glfwDestroyWindow(this->pGLFWwindow);
  glfwTerminate();
}
