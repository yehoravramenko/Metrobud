#include "window.hpp"

using namespace Metrobud;

Window::Window() {
  RGFW_setGLVersion(RGFW_GL_CORE, 4, 6);

  this->pWindow = std::unique_ptr<RGFW_window>(
      RGFW_createWindow("metrobud", RGFW_RECT(0, 0, 800, 600),
                        (u16)(RGFW_CENTER | RGFW_NO_RESIZE)));

  assert(this->pWindow);

  RGFW_window_makeCurrent(this->pWindow.get());
  int glLoad_result = gladLoadGLLoader((GLADloadproc)RGFW_getProcAddress);

  assert(glLoad_result);
}

void Window::Update() {
  RGFW_window_checkEvents(this->pWindow.get(), 0);
  RGFW_window_swapBuffers(this->pWindow.get());
}

void Window::Exit() {
  RGFW_window_close(this->pWindow.get());
}

bool Window::shouldClose() {
  return RGFW_window_shouldClose(this->pWindow.get()) == RGFW_TRUE;
}

std::array<int, 4> Window::getRect() {
  return {this->pWindow->r.x, this->pWindow->r.y, this->pWindow->r.w,
          this->pWindow->r.h};
}