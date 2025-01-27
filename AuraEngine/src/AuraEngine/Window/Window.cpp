#include "Window.hpp"
#include "../Log/Log.hpp"

namespace AuraEngine
{
  Window::Window()
  {
    Log::EngineLog.Info("Window called");

    if (!glfwInit())
      Log::EngineLog.Error("Failed to initialize GLFW");

    this->window = glfwCreateWindow(800, 600, "Aura Engine", nullptr, nullptr);
    if (!this->window)
      Log::EngineLog.Error("Failed to create window");
  }

  void Window::Update()
  {
    glfwPollEvents();
    glfwSwapBuffers(this->window);
  }

  void Window::SetSize(const std::pair<int, int>& size)
  {
      glfwSetWindowSize(this->window, size.first, size.second);
  }

  void Window::SetTitle(const std::string& title)
  {
      glfwSetWindowTitle(this->window, title.c_str());
  }

  bool Window::ShouldClose()
  {
      return glfwWindowShouldClose(this->window) == GLFW_TRUE;
  }

  Window::~Window()
  {
    glfwTerminate();
  }
}