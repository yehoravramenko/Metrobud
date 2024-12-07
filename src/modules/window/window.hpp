#pragma once

#include <common.hpp>

// typedef struct Window {
//   GLFWwindow *pGLFWWindow;
// } Window;

// Window *g_Window();

// void Window_Init(vec2 *windowSize);
// void Window_Update(bool *isRunning);
// void Window_Exit();

class Window {
public:
  vec2 size;

  Window();
  void Update(bool &isRunning);
  ~Window();

private:
  GLFWwindow *pGLFWwindow;
};